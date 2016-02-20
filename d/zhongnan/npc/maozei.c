//Cracked by Roath
//d/zhongnan/npc/maozei.c
//maozei 毛贼
// sdong 08/98

#include <ansi.h>
inherit NPC;

void create()
{
		  set_name("毛贼", ({ "mao zei","zei","robber" }) );
		  set("gender", "男性");
		  set("age", 35+random(5));
		  set("long",
					 "这家伙高头大马，专干打家劫舍的勾当。\n");
		  set("combat_exp", 4500);
		  set("shen_type", -1);
		  set("attitude", "heroism");

		  set("apply/attack",  30);
		  set("apply/defense", 30);

		  set("chat_chance", 5);
		  set("chat_msg", ({
		  }) );

		  set_skill("sword", 20);
		  set_skill("blade", 20);
		  set_skill("halberd", 20);
		  set_skill("axe", 20);
		  set_skill("unarmed", 20);
		  set_skill("parry", 20);
		  set_skill("dodge", 20);

		  setup();
		  switch( random(8) )
		  {
					 case 0:
								carry_object("/clone/weapon/gangjian")->wield();
								break;
					 case 1:
								carry_object("/clone/weapon/gangdao")->wield();
								break;
					 case 2:
								carry_object("/clone/weapon/banfu")->wield();
								break;
					 case 3:
								carry_object("/clone/weapon/qiang")->wield();
								break;
					 case 4:
								carry_object("/clone/weapon/changbian")->wield();
								break;
					 case 5:
								carry_object("/clone/weapon/gangzhang")->wield();
								break;
					 case 6:
								carry_object("/clone/weapon/qimeigun")->wield();
								break;
					 case 7:
								carry_object("/clone/weapon/zhubang")->wield();
								break;
		  }

		  carry_object("/clone/misc/cloth")->wear();
		  add_money("silver", 1);
        call_out("destruct_me",120+random(60),this_object());
}


void init()
{
		  object victim = this_player();
		  object *inv, me = this_object();
		  mapping skill_status;
		  string *sname;
		  int i, max = 0, j;

					  if( interactive(victim))
						{
								if( me->query_temp("fought") && query_temp("victim") && victim->query("id") == query_temp("victim") )
								{
										  me->kill_ob(victim);
										  victim->kill_ob(me);
										  message_vision( "$n对着$N大吼：明年的今天就是你的忌日！\n", victim, me );
										  remove_call_out("checking");
										  call_out("checking", 25, me, victim,me->query_temp("bonus",1));
										  return;
								}
						}


		  if ( !me->query_temp("said") ) {
				 switch( random(3) )
				 {
					 case 0:
								command( "rob" );
								command( "say 识相点儿，草药留下来就让你死牛鼻子走！" );
								break;
					 case 1:
								command( "grin" );
								command( "say 相好的，听说这儿的草药很邪门，留下你的草药滚吧！" );
								break;
					 case 2:
								command( "hehe" );
								command( "say 大爷听说全真教的臭道士炼丹很灵，特来看看用什么药炼的。你留下草药滚吧！" );
								break;
				 }
				 me->set_temp("said", 1);
             call_out("destruct_me",120+random(60),me);
		  }

		  if ( !me->query_temp("copied") ) {
			  if ( mapp(skill_status = victim->query_skills()) ) {
					 skill_status = victim->query_skills();
					 sname = keys(skill_status);

					 for(i=0; i<sizeof(skill_status); i++) {
								if ( skill_status[sname[i]] > max ) max = skill_status[sname[i]];
					 }

					 if( victim->query("combat_exp",1) > 15000 )max = max*4/3;
					 else if( victim->query("combat_exp",1) > 100000 )max = max*2;
					 else if( victim->query("combat_exp",1) > 500000 )max = (int)(max*5/2);
					 else if( victim->query("combat_exp",1) > 1500000 )max = (int)(max*6/2);

					 me->set_skill("force", max*2+random(max/2));
					 me->set_skill("dodge", max/2+random(max)/2);
					 me->set_skill("parry", max/2+random(max)/2);
					 me->set_skill("cuff", max/2+random(max)/2);
					 me->set_skill("sword", max/2+random(max)/2);
					 me->set_skill("blade", max/2+random(max)/2);
					 me->set_skill("halberd", max/2+random(max)/2);
					 me->set_skill("stick", max/2+random(max)/2);
					 me->set_skill("axe", max/2+random(max)/2);
					 me->set_skill("staff", max/2+random(max)/2);
					 me->set_skill("wuxing-quan", max/2);
					 me->set_skill("wuxingbu", max/2+random(max)/2);
					 me->set_skill("club", max/2+random(max)/2);


					 me->set("combat_exp", victim->query("combat_exp",1)+random(victim->query("combat_exp",1)));
					 me->set("max_qi", victim->query("max_qi"));
					 me->set("max_neili", victim->query("max_neili"));
					 me->set("neili", victim->query("max_neili"));
					 me->set("eff_qi", victim->query("max_qi"));
					 me->set("max_jing", victim->query("max_jing"));
					 me->set("eff_jing", victim->query("max_jing"));
					 me->set("qi", me->query("max_qi"));
					 me->set("jing", me->query("max_jing"));
					 me->set("shen",-1*victim->query("combat_exp")/5);

					 me->set("no_sing", 1);
					 me->set_temp("copied", 1);

		  inv = all_inventory(victim);

					 for (j=0; j<sizeof(inv); j++) {
					 if(inv[j]->is_unique() && random(5) == 1)
					 map_skill("cuff", "wuxing-quan");
					 map_skill("dodge", "wuxingbu");
					 map_skill("parry", "wuxing-quan");
					 prepare_skill("cuff", "wuxing-quan");

					 }
		  }
		  if ( !me->query_temp("victim") ) {
					 remove_call_out("rob_kill");
					 call_out("rob_kill", 40, me, victim);
					 me->set_temp("victim", victim->query("id"));
		  } else if( (string)victim->query("id") == (string)me->query_temp("victim") ) {
					 remove_call_out("rob_kill");
					 call_out("rob_kill", 2, me, victim);
					 }
		  }

		  //if ( userp(this_player()) && !me->is_fighting() && me->query_temp("fought") )
		  //			 call_out("destruct_me", 1, me);

//      remove_call_out("checking");
//              call_out("checking", 45, me, victim);

}



void destruct_me(object me)
{
		  if ( me && objectp(me) )
		  {
			 message_vision("$N往大岩石上一跳，转眼就不见了\n", this_object());
			 destruct(me);
		  }
}

int accept_object(object who, object ob)
{
		  object me = this_object();

		  if ( me->query_temp("fought", 1) ) {
					 command( "grin" );
					 command( "say 现在才给已太迟了，老子我宝贝也要，命也要！纳命来吧！" );
					 return 0;
		  }

		  if (
				 ob->query("id") == "chuanbei" ||
				 ob->query("id") == "fuling" ||
				 ob->query("id") == "gouzhi zi" ||
				 ob->query("id") == "heshouwu" ||
				 ob->query("id") == "huanglian" ||
				 ob->query("id") == "jugeng" ||
				 ob->query("id") == "jinyin hua" ||
				 ob->query("id") == "shengdi"
			)
			{
					 remove_call_out("rob_kill");
					 who->delete_temp("rob_victim");
					 message_vision( "$n飞起一脚踢在$N的屁股上，不屑地哼了一声。\n", who, me);
					 command( "say 算你识时务，老子今天放你一马，快滚吧！" );
					 message_vision( "$N说完便扬长而去。\n", me );
					 call_out("destruct_me", 1, me);
					 return 1;
		  }
		  else {
					 command( "say 大爷要的是草药，你这龟儿子可是耍老子来着？" );
					 return 0;
		  }
}

void rob_kill(object me, object victim)
{
		  if( !objectp(victim) )
					 victim = present((string)me->query_temp("victim"), environment(me) );
		  if( !objectp(me) || !objectp(victim) ) return;
		  message_vision( "$n对着$N大吼：你竟敢不交！老子宰了你！\n", victim, me );
		  me->set_temp("fought", 1);
		  me->kill_ob(victim);
		  remove_call_out("checking");
		  call_out("checking", 1, me, victim,me->query_temp("bonus",1));
}


int checking(object me, object victim,int bonus)
{
	if ( !me  ) {
		return 1;
	}

	if( !present(victim, environment(me)) )
		return 1;

	me->set_temp("bonus",bonus);


//	if ( !victim=find_player(me->query_temp("victim")) ) {
//		remove_call_out("destruct_me");
//		call_out("destruct_me", 1, me);
//		return 1;
//	}

	if ( victim->is_ghost() ) {
		command("grin");
		command("say 总算大功告成了！哈哈哈！");

		remove_call_out("destruct_me");
		call_out("destruct_me", 1, me);
		return 1;
	}

	if ( !me->is_fighting() && present(victim, environment(me)) && me->query("qi",1)>0 ) {
		me->kill_ob(victim);
		message_vision( "$n对着$N大吼：大爷我杀了你！\n", victim, me );

		remove_call_out("checking");
		call_out("checking", 1, me, victim,bonus+random(2) );
		return 1;
	}


	remove_call_out("checking");
	call_out("checking", 1, me, victim,bonus+random(2));
	return 1;
}



int accept_fight(object victim)
{
		  object me = this_object();

		  command( "say 你吃了狼心豹子胆啦，竟敢反抗！让我送你见阎王爷去吧！" );
		  me->set_temp("fought", 1);
		  me->kill_ob(victim);
		  victim->kill_ob(me);
		  remove_call_out("checking");
		  call_out("checking", 1, me, victim,me->query_temp("bonus",1));
		  return 1;
}

int accept_kill(object victim)
{
		  object me = this_object();

		  command( "say 不知死活的东西，让大爷我超渡你吧！" );
		  me->kill_ob(victim);
		  remove_call_out("checking");
		  call_out("checking", 1, me, victim,me->query_temp("bonus",1));
		  return 1;
}

void unconcious()
{
		  object me=this_object();
		  object ob = me->query_temp("last_damage_from");

		  if( random(30) == 10 && ob)
		  {
				 if( !living(me) ) {revive(1);reincarnate();}
					 message_vision("\n$N恨恨地说道：没想到你这小子爪子这么硬，下次再找你麻烦。\n", this_object());
					 message_vision("$N往大岩石上一跳，转眼就不见了\n", this_object());
					 destruct(me);
					 tell_object(ob,"\n你觉得自己对武功有点所悟！\n");
					 ob->add("potential", me->query_temp("bonus",1)/10);
					 if(ob->query("potential",1)>ob->query("max_potential",1) )
								ob->set("potential",ob->query("max_potential",1));
					 ob->delete_temp("herb_victim");
		  }


		 ::unconcious();
}


void die()
{
		  int pot,exp;
		  object me=this_object();
		  object ob = me->query_temp("last_damage_from");

		 if( !living(me) ) {revive(1);reincarnate();}

		  if(!ob || me->query("combat_exp",1) < ob->query("combat_exp",1)/2 )
		  {
					 ::die();
					 return;
		  }


		  if( random(2) == 0 )
		  {
					 exp = 6*me->query_temp("bonus",1)+6*random(me->query_temp("bonus",1));
					 if(exp<50)exp=50;
					 if(exp>140)exp=140;
					 pot = 3*me->query_temp("bonus",1)+3*random(me->query_temp("bonus",1));
					 if(pot<25)pot=25;
					 if(pot>65)pot=65;
					 ob->add("combat_exp", exp);
					 ob->add("potential", pot);
					 if ( ob->query("potential") > ob->query("max_potential") )
								ob->set("potential", ob->query("max_potential"));
					 tell_object(ob,"\n你隐隐感觉打架的经验好象长了一些！\n");
					 ::die();
		  }
		  else
		  {
					 message_vision(HIR"\n大岩石上忽然有人跳下来，把$N一把抱起，喝道：恶贼，休伤我的兄弟。\n"NOR, this_object());
					 message_vision("毛贼带着$N往大岩石上一跳，转眼就不见了。\n", this_object());
					 tell_object(ob,"\n你觉得自己对武功有点所悟！\n");
					 ob->add("potential",me->query_temp("bonus",1)*2 );
					 if(ob->query("potential",1)>ob->query("max_potential",1) )
								ob->set("potential",ob->query("max_potential",1));
					 destruct(me);
		  }
}


