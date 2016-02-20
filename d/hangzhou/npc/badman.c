//Cracked by Roath
///d/hangzhou/badman.c 蒙面人
// sdong 07/98

inherit NPC;

void create()
{
	set_name("密宗弟子", ({ "mengmian ren","ren","mengmian" }) );
	set("gender", "男性");
	set("age", 25+random(25));
	set("long",
		"这家伙黑巾蒙面，双眸均有杀气，时不时低沉地阴笑。\n");
	set("combat_exp", 5000);
	set("shen_type", -1);
	set("attitude", "heroism");

	set("chat_chance", 5);
	set("chat_msg", ({
	}) );

	setup();

	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", random(5));
}
void init()
{
	object victim = this_player();
	object *inv, me = this_object();
	mapping skill_status;
	string *sname;
	int i, max = 0, max1, j;



	if ( !me->query_temp("copied") ) {
	   if ( mapp(skill_status = victim->query_skills()) ) {
		skill_status = victim->query_skills();
		sname = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++) {
			if ( skill_status[sname[i]] > max ) max = skill_status[sname[i]];
		}
		

		max1 = (int)max*3/4 + 1;
		max = (int)max*3/4 + 1 + random((int)max/4);
		
		me->set_skill("dodge", max1);
		me->set_skill("parry", max1 );
		me->set_skill("force", max1);
		switch( random(4) )
		{
			case 0:
				set_name("雪山弟子", ({ "xueshan dizi","dizi" }) );
				me->set_skill("cuff", max1);
				me->set_skill("yujiamu-quan", max1);
				me->map_skill("cuff", "yujiamu-quan");
				me->prepare_skill("cuff", "yujiamu-quan");
				me->set_skill("hand", max1);
				me->set_skill("dashou-yin", max1);
				me->map_skill("hand", "dashou-yin");
				me->prepare_skill("hand", "dashouyin");
				me->set_skill("longxiang-banruo", max1);
				me->map_skill("force", "longxiang-banruo");
				me->set_skill("shenkongxing", max1);
				me->map_skill("dodge", "shenkongxing");
				switch( random(2) ) {
				   case 0:
					me->set_skill("staff", max);
					me->set_skill("jingang-chu", max);
					me->map_skill("staff", "jingang-chu");
					me->map_skill("parry", "jingang-chu");
					me->carry_object("/clone/weapon/tiezhang")->wield();
					break;
				   case 1:
					me->set_skill("sword", max);
					me->set_skill("mingwang-jian", max);
					me->map_skill("sword", "mingwang-jian");
					me->map_skill("parry", "mingwang-jian");
					me->carry_object("/clone/weapon/changjian")->wield();
					break;
				}
				break;
			case 1:
				set_name("星宿弟子", ({ "xingxiu dizi","dizi" }) );
				me->set_skill("strike", max1);
				me->set_skill("chousui-zhang", max1);
				me->map_skill("strike", "xingxiu-duzhang");
				me->prepare_skill("strike", "xingxiu-duzhang");
				me->set_skill("claw", max1);
				me->set_skill("sanyin-zhua", max1);
				me->map_skill("claw", "sanyin-zhua");
				me->prepare_skill("claw", "sanyin-zhua");
				me->set_skill("huagong-dafa", max1);
				me->map_skill("force", "huagong-dafa");
				me->set_skill("staff", max);
				me->set_skill("tianshan-zhang", max);
				me->map_skill("staff", "tianshan-zhang");
				me->set_skill("zhaixinggong", max1);
				me->map_skill("dodge", "zhaixinggong");
				me->map_skill("parry", "tianshan-zhang");
				me->carry_object("/clone/weapon/tiezhang")->wield();
				break;
			case 2:
				set_name("神龙弟子", ({ "shenlong dizi","dizi" }) );
				me->set_skill("strike", max1);
				me->set_skill("lingshe-shenfa", max1);
				me->map_skill("dodge", "lingshe-shenfa");
				me->set_skill("huagu-mianzhang", max1);
				me->map_skill("strike", "huagu-mianzhang");
				me->prepare_skill("strike", "huagu-mianzhang");
				me->set_skill("kick", max1);
				me->set_skill("jueming-tui", max1);
				me->map_skill("kick", "jueming-tui");
				me->prepare_skill("kick", "jueming-tui");
				me->set_skill("dulong-dafa", max1);
				me->map_skill("force", "dulong-dafa");
				me->set_skill("ruyi-gou", max);
				me->map_skill("hook", "ruyi-gou");
				me->set_skill("hook", max);
				me->carry_object("/clone/weapon/hook")->wield();
				break;
			case 3: 
				set_name("白驼山弟子", ({ "baituo dizi","dizi" }) );
				me->set_skill("strike", max1);
				me->set_skill("hamagong", max1);
				me->set_skill("hand", max1);
				me->set_skill("shexing-diaoshou", max1);
				me->map_skill("hand", "shexing-diaoshou");
				if ( max > 100 ) {
					me->map_skill("strike", "hamagong");
					me->prepare_skill("strike", "hamagong");
				}
				else {
					me->prepare_skill("hand", "shexing-diaoshou");
				}
				me->map_skill("force", "hamagong");
				me->set_skill("staff", max);
				me->set_skill("lingshe-zhang", max);
				me->map_skill("staff", "lingshe-zhang");
				me->map_skill("parry", "lingshe-zhang");
				me->set_skill("chanchubu", max1);
				me->map_skill("dodge", "chanchubu");
				me->carry_object("/clone/weapon/tiezhang")->wield();
				break;
		}

		me->set("combat_exp", victim->query("combat_exp")+random(victim->query("combat_exp")/10));
		me->set("max_qi", victim->query("max_qi"));
		me->set("eff_qi", victim->query("max_qi"));
		me->set("max_jing", victim->query("max_jing"));
		me->set("eff_jing", victim->query("max_jing"));
		me->set("qi", me->query("max_qi"));
		me->set("jing", me->query("max_jing"));
		me->set("jiali", victim->query("jiali")*3/4);
		if ( victim->query("max_neili") > 0 ) {
			me->set("max_neili", victim->query("max_neili"));
		}
		else me->set("max_neili", 500);
		if ( victim->query("max_jingli") > 0 ) {
			me->set("max_jingli", victim->query("max_jingli"));
		}
		else me->set("max_jingli", 500);
		me->set("neili", me->query("max_neili"));
		me->set("jingli", me->query("max_jingli"));
		
		me->set("no_sing", 1);
		me->set_temp("copied", 1);
	}

	if ( !me->query_temp("said") ) {
	     switch( random(4) )
	     {
		case 0:
			command( "grin" );
			command( "say 就凭你秃驴的三脚猫功夫，也配在这里指教人家，让老子来教训教训你，看招！" );
			break;
		case 1:
			command( "hehe" );
			command( "say 听说这个镖局油水很多，老子千里迢迢赶来。秃贼，你就认命吧！" );
			break;
		case 2:
			command( "hehe" );
			command( "say 去年俺兄弟死在你这秃贼的手里，大爷我为兄弟报仇来了。秃贼，你就认命吧！" );
			break;
		default:
			command( "hehe" );
			command( "say 大爷我奉命来扫平这个镖局。秃贼，你就认命吧！" );
			break;
	     }
		  me->set_temp("said", 1);
		  call_out("destruct_me",100+random(60),me);
	}

	if ( !me->query_temp("victim") ) {
		me->set_temp("victim", victim->query("id"));
		me->set_temp("fought", 1);
		message_vision( "$n对着$N狞笑道：明年的今天就是你的忌日！\n", victim, me );
		me->kill_ob(victim);
		victim->kill_ob(me);

		remove_call_out("checking");
		call_out("checking", 1, me, victim);
	} 
	else if( present(me->query_temp("victim"),environment(me))
	&& !me->is_fighting() && me->query_temp("copied") ) {
		me->kill_ob(victim);
		message_vision( "$n对着$N大吼：明年的今天就是你的忌日！\n", victim, me );
		
		remove_call_out("checking");
		call_out("checking", 1, me, victim,0);
		}
	}  

		  if( interactive(victim))
		  {
			if( victim->query("id") == query_temp("victim") )
			{
				me->kill_ob(victim);
				message_vision( "$n对着$N大吼：明年的今天就是你的忌日！\n", victim, me );
				remove_call_out("checking");
				call_out( "checking", 1, me, victim,me->query_temp("bonus",1) );
			}
		  }

}

void destruct_me(object me)
{
	if(me) {
		message_vision("$N匆匆忙忙地离开了。\n\n", me);
		destruct(me);
	}
}

int checking(object me, object victim,int bonus)
{
	if ( !me  ) {
		return 1;
	}

	if( !present(victim, environment(me)) )
		return 1;

	me->set_temp("bonus",bonus);

	
	if ( !victim=find_player(me->query_temp("victim")) ) {
		remove_call_out("destruct_me");
		call_out("destruct_me", 1, me);
		return 1;
	}
	
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

	command( "say 你吃了狼心豹子胆啦，竟敢反抗！" );
	me->set_temp("fought", 1);
	me->kill_ob(victim);

	remove_call_out("checking");
	call_out("checking", 1, me, victim,me->query_temp("bonus",1)+random(2));
	return 1;
}

int accept_kill(object victim)
{
	object me = this_object();

	command( "say 不知死活的东西，让大爷我超渡你吧！" );
	me->kill_ob(victim);

	remove_call_out("checking");
	call_out("checking", 1, me, victim,me->query_temp("bonus",1)+random(2));
	return 1;
}

void unconcious()
{
	object me=this_object();
	object ob = me->query_temp("last_damage_from");

	if( random(20) == 10)
	{
		message_vision("\n$N恨恨地说道：没想到你这小子爪子这么硬，下次再找你麻烦。\n", this_object());
		message_vision("$N往墙上一跳，匆匆忙忙离开了。\n", this_object());
		destruct(me);
		tell_object(ob,"\n你的潜能好象增加了！\n");
		ob->add("potential", me->query_temp("bonus",1)/10);
		if(ob->query("potential",1)>ob->query("max_potential",1) )
			ob->set("potential",ob->query("max_potential",1));
	}
	::unconcious();

}

void die()
{
	int pot,exp;
	object me=this_object();
	object ob = me->query_temp("last_damage_from");

    if( !living(me) ) {revive(1);reincarnate();}

	if( me->query("combat_exp") > ob->query("combat_exp")/2 && random(2) == 0)
	{
		exp = 6*me->query_temp("bonus",1)+6*random(me->query_temp("bonus",1));
		if(exp<50)exp=50;
		if(exp>140)exp=140;
		pot = 3*me->query_temp("bonus",1)+3*random(me->query_temp("bonus",1));
		if(pot<25)pot=25;
		if(pot>65)pot=65;
		ob->add("combat_exp", exp/4);
		ob->add("potential", pot/4);
		if ( ob->query("potential") > ob->query("max_potential") )
			ob->set("potential", ob->query("max_potential"));
		tell_object(ob,"\n你的经验和潜能好象进步了！\n");
		::die();
	}
	else
	{	
		message_vision("\n墙上忽然有人跳下来，把$N一把抱起，喝道：秃贼，休伤我的兄弟。\n", this_object());
		message_vision("蒙面人带着$N往墙上一跳，匆匆忙忙离开了。\n", this_object());
		tell_object(ob,"\n你的潜能好象增加了！\n");
		ob->add("potential",me->query_temp("bonus",1)*2 );
		if(ob->query("potential",1)>ob->query("max_potential",1) )
			ob->set("potential",ob->query("max_potential",1));
		destruct(me);
	}
}

