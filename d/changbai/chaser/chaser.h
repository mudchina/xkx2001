//Cracked by Roath
// /d/changbai/npc/chaser.h;
// by ALN 1/98
// modified by sdong : setup chaser's skill according to victim's
//                     if victim has more wanted stuff, chaser more tougher
//  6/98

#include "wanted_list.h"

void do_chaser_ask(object);
void do_chaser_kill(object);
void chaser_flee(object);
void setup_skill(object me,object victim);
int number_goodstuff(object victim);


void chaser_check()
{
		  object chaser_ob, ob, env, envenv, victim, room, dest;
		  int period;

		  if( !living(chaser_ob = this_object()) ) return;

		  call_out("chaser_check", 1);

		  if( chaser_ob->is_busy() ) return;

	 // chaser will leave if no such weapons in xkx
		  if( !objectp(ob = chaser_ob->query("stuff")) ) {
					 chaser_flee(chaser_ob);
					 return;
		  }

	 // if chaser alreadys takes the weapon, then leaves
		  env = environment(ob);
		  if( env == chaser_ob ) {
					 COMMAND_DIR"std/halt"->main(chaser_ob);
					 chaser_flee(chaser_ob);
					 return;
		  }

	 // if the weapon is on the floor, chaser picks it up and leaves
		  room = environment(chaser_ob);
		  if( env == room ) {
					 COMMAND_DIR"std/halt"->main(chaser_ob);
					 GET_CMD->do_get(chaser_ob, ob);
					 chaser_flee(chaser_ob);
					 return;
		  }

	 // i use yaodai to express all containers or corpses
	 // if the weapon is in the yaodai, and the yaodai is on the floor
	 // chase picks up the weapon from the yaodai and leaves
		  envenv = environment(env);
		  if( !userp(env) && envenv == room ) {
					 COMMAND_DIR"std/halt"->main(chaser_ob);
					 GET_CMD->do_get(chaser_ob, ob);
					 chaser_flee(chaser_ob);
					 return;
		  }

	 // if the weapon is in the yaodai, and the yaodai is in the corpse
	 // chase picks up the yaodai from the corpse and leaves
		  if( !userp(envenv) && environment(envenv) == room ) {
					 COMMAND_DIR"std/halt"->main(chaser_ob);
					 GET_CMD->do_get(chaser_ob, env);
					 chaser_flee(chaser_ob);
					 return;
		  }

	 // if chaser follows the player to wumiao, then chaser leaves
//		  if( room->query("no_fight") ) {
//					 chaser_flee(chaser_ob);
//					 return;
//		  }

	 // find the player who takes the weapon
		  if( userp(env) ) {victim = env;}
	 // find the player who takes the yaodai
		  else if( userp(envenv) ) {victim = envenv; ob = env;}
	 // if no player takes the weapon or the yaodai, then chaser leaves
		  else {
					 chaser_flee(chaser_ob);
					 return;
		  }

		  dest = environment(victim);
// if the player goes to wumiao, then chaser leaves
//		  if( dest->query("no_fight") ) {
//                chaser_flee(chaser_ob);
//					 return;
//		  }

	 // if the player who takes the weapon or the yaodai flees away,
	 // then chaser goes to catch it
		  if( dest != room ) {
					 message("vision",
								chaser_ob->name() + "急急忙忙地离开了。\n",
								environment(chaser_ob), ({chaser_ob}));
					 chaser_ob->move(dest);
					 message("vision",
								chaser_ob->name() + "走了过来。\n",
								environment(chaser_ob), ({chaser_ob}));
					 message_vision(HIR"$N对$n大声喝道：" + RANK_D->query_rude(victim) + "我看你这次还往哪里跑？！\n\n"NOR, chaser_ob, victim);
					 ob->set_leader(victim);
					 ob->kill_ob(victim);
					 return;
		  }

	 // ok chaser finally catchs the player who takes the weapon or the yaodai

	 // if the player is faint or sleeps, chaser should not kill the player,
	 // just take away the weapon or the yaodai and then leave
		 if( !living(victim) ) {
					 COMMAND_DIR"std/halt"->main(chaser_ob);
					 GET_CMD->do_get(chaser_ob, ob);
					 chaser_flee(chaser_ob);
					 return;
		 }

	 // then the chaser has to take some actions against the player
		 if( chaser_ob->query("victim") != victim ) {
					 COMMAND_DIR"std/halt"->main(chaser_ob);
					 chaser_ob->set("victim", victim);
		 }

		 if( chaser_ob->query_leader() != victim ) {
					 COMMAND_DIR"std/halt"->main(chaser_ob);
					 chaser_ob->set_leader(victim);
		 }

		 chaser_ob->add("period", 1);
		 period = (int)chaser_ob->query("period");

		 if( !chaser_ob->query("asked") )
					 do_chaser_ask(chaser_ob);
		 else if( period > 10 + random(10) && period < 30 + random(30) && !chaser_ob->query("angry") )
					 do_chaser_kill(chaser_ob);
		 else if( chaser_ob->query("angry") && !chaser_ob->is_fighting(victim) )
					 chaser_ob->kill_ob(victim);
}

void do_chaser_ask(object chaser_ob)
{
		  object victim;
		  if( !chaser_ob || !living(chaser_ob) ) return;
		  if(  chaser_ob->query("angry")
		  ||   chaser_ob->query("asked") ) return;

		  if( !objectp(chaser_ob->query("stuff")) ) return;

		  victim = chaser_ob->query("victim");
		  if( !victim || !living(victim)
		  ||   environment(chaser_ob) != environment(victim) ) return;

		  message_vision(HIR"\n$N对$n大声喝道：" + RANK_D->query_rude(victim) + "！凭你也配这种武林宝物！还不赶快孝敬老子！！！\n"NOR, chaser_ob, victim);
		  chaser_ob->set("asked", 1);
		  setup_skill(chaser_ob,victim);
}

void do_chaser_kill(object chaser_ob)
{
		  object victim;

		  if( !chaser_ob || !living(chaser_ob) ) return;
		  if( !chaser_ob->query("asked") ) return;

		  if( !objectp(chaser_ob->query("stuff")) ) return;

		  victim = chaser_ob->query("victim");
		  if( !victim || !living(victim)
		  ||   environment(chaser_ob) != environment(victim) ) return;

		  message_vision(HIR"\n$N对$n大声喝道：" + RANK_D->query_rude(victim) + "！竟敢不识好歹！！！\n"NOR, chaser_ob, victim);
		  chaser_ob->set("angry", 1);
}

void chaser_flee(object chaser_ob)
{
		  object room;

		  if( room = environment(chaser_ob) ) {
		  message("vision",
					 chaser_ob->name() + "急急忙忙地离开了。\n",
					 room, ({chaser_ob}));
		  }
		  chaser_ob->move("/d/shenlong/cangku");
		  DROP_CMD->main(chaser_ob, "all");
		  destruct(chaser_ob);
}

void destroy_chaser(object chaser_ob)
{
		  if( chaser_ob->is_busy() || !living(chaser_ob) ) return;

		  message("vision",
					 chaser_ob->name() + "急急忙忙地离开了。\n",
					 environment(chaser_ob), ({chaser_ob}));
		  destruct(chaser_ob);
}


int accept_object(object who, object ob)
{
		  object chaser_ob = this_object();
		  object obj = chaser_ob->query("stuff");

		  if( environment(obj) != ob && obj != ob )
					 return notify_fail("滚！！！老子要的是"+obj->name()+"！！！\n");

		  command("nod " + who->query("id"));

		  command("say 你还算识时务，就放你一马吧。");
		  if( chaser_ob->is_fighting() || chaser_ob->is_busy() )
					 COMMAND_DIR"std/halt"->main(chaser_ob);
		  call_out("chaser_flee", 1, chaser_ob);
		  return 1;
}

// setup the chaser's skill according to victim's
//  by sdong

void setup_skill(object me,object victim)
{
	object *inv;
	mapping skill_status;
	string *sname;
	int i, max = 0, max1, j;

		if ( mapp(skill_status = victim->query_skills()) ) {
		skill_status = victim->query_skills();
		sname = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++) {
			if ( skill_status[sname[i]] > max ) max = skill_status[sname[i]];
		}

		}

		max1 = (int)max*3/4 + 1;
		max = (int)max*3/4 + (8+random((int)max/24) )*number_goodstuff(victim);
      if(max>270)max=270;


		me->set("combat_exp", victim->query("combat_exp")+random(victim->query("combat_exp")/10));
		me->set("max_qi", victim->query("max_qi"));
		me->set("eff_qi", victim->query("max_qi"));
		me->set("max_jing", victim->query("max_jing"));
		me->set("eff_jing", victim->query("max_jing"));
		me->set("qi", me->query("max_qi"));
		me->set("jing", me->query("max_jing"));
		me->set("jiali", victim->query("jiali")*3/4);

		if(victim->query("shen")<0)
		{
			me->set("shen", me->query("combat_exp") /20);
		}
		else me->set("shen",-1 * me->query("combat_exp")/20);

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

		if ( mapp(skill_status = me->query_skills()) ) {
		skill_status = me->query_skills();
		sname = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++) {
			me->set_skill(sname[i],max);
		}
      }

		me->set_skill("dodge", max1);
		me->set_skill("parry", max1 );

}

int number_goodstuff(object victim)
{
		  object *obj, ob, owner, rum_ob, *owners;
		  string filename, *filenames;
		  int i, nStuff = 0;

		  filenames = keys(wanted_list);
		  for(i = 0; i < sizeof(filenames); i++)
		  {
					 filename = filenames[i];
					 obj = filter_array(children(filename), (: clonep :));
					 if( sizeof(obj) < 1 ) continue;
					 ob = obj[0];
					 if( (int)ob->query("value") < 100 ) continue;

					 if( !(owner = environment(ob)) ) continue;

					 if( owner == victim ) nStuff++;
		 }

		 return nStuff;
}



