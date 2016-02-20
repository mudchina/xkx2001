//Cracked by Roath
// road: /zhongnan/fengdong.c
// by sdong 08/98

#include <ansi.h>
#include <room.h>
inherit ROOM;
private int blow_result(object victim);
void blow();
void setup_ob(object me,object victim);

void create()
{
		  set("short","风洞");

		  set("long",@LONG
这个大洞又高又宽，由两大花岗岩夹峙而成。洞内清风习习，凉气飕飕，
故称风洞。听说有时会狂风大作，看来要小心一些。
LONG);

		  set("exits",([
								"out": __DIR__"shanlu18",
							 ])
			  );
	  set("cost",1);
	  setup();
}

void init()
{
	add_action("do_throw", "throw");
	remove_call_out("blow");
	call_out("blow",3 + random(3) );
}

int do_throw(string arg)
{
	object ob;
	if(!arg)return notify_fail("你想扔什么？");
	ob = present(arg,this_player());
	if(!ob)return notify_fail("你想扔什么？");
	message_vision( HIY"\n$N把$n往外扔去！\n"NOR, this_player(), ob);
	remove_call_out("blow");
	call_out("blow",1  );
	if(userp(ob))
	{
		ob->move("/d/zhongnan/shanlu18");
		message_vision( HIY"\n$N被扔了出来！\n"NOR, ob);
	 }
	else destruct(ob);
	return 1;
}


int blow()
{
	object *inv = all_inventory(find_object("d/zhongnan/fengdong"));
	object ob, me= this_player();
	int i;

	if( !this_player() ) return 1;
	if(!environment(this_player())) return 1;
	if( base_name(environment(this_player())) != "/d/zhongnan/fengdong") return 1;

	message_vision( HIY"\n突然一阵狂风夹带石块向风洞袭来，声势惊人！\n"NOR, this_player() );

	for ( i=0 ; i < sizeof(inv); i++)
	{
		if ( (string)inv[i]->query("race") == "人类" )
		{
			blow_result(inv[i]);
		}
	}

	remove_call_out("blow");
	call_out( "blow",3 + random(3) );
	return 1;
}

private int blow_result(object victim)
{
	object ob2,ob;
	string *limbs, str, dodge_skill, limb, result;
	int ap, dp, damage;

	if(random(100)==1)
	{
		ob2=new("/d/zhongnan/npc/bigbear");
		ob2->move(environment(victim));
		message_vision(HIR"突然从洞口中走进一只$N，它看到有人，大概受了惊吓，发疯似地向$n发起进攻！\n"NOR, ob2,victim);
		setup_ob(ob2,victim);
		ob2->kill_ob(victim);
		ob2->add_temp("offenders/"+victim->query("id"), 1);
		ob2->start_busy(1+random(3));
      victim->kill_ob(ob2);
	}

	ap = victim->query_dex()+victim->query_str();
	dp = victim->query_dex();
	ap *= victim->query("combat_exp")/1000;
	dp *= victim->query("combat_exp")/1000;
	ap = random(ap);

	ob = new ("/d/city/obj/stone");

	if ( ap > dp){
	limbs = victim->query("limbs");
		victim->receive_wound("qi", random(20), "被石块砸死了！");
		victim->receive_damage("qi", random(ob->query_weight()/100), "被石块砸死了！");

		message_vision(CYN"$N猝不及防，$n"+CYN+"砸在了$N的"+limbs[random(sizeof(limbs))]
			  +"上。\n"NOR, victim, ob);
		destruct(ob);
		//ob->move(environment(victim));
	}
	else if ( ap < dp/7 && ob->query_weight() < 7000
		&& victim->query("race") == "人类"){
		message_vision(CYN"不料$N眼明手快，身子一侧，把$n"+CYN+"轻轻地接在手里。\n\n"NOR, victim, ob);

		ob->move(victim);

	 }
	else {

		dodge_skill = victim->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		message_vision("$N一闪，正好躲过"+ob->query("name")+".\n", victim);

		destruct(ob);
	}

	if( victim->query_skill("parry",1) < 300 ) victim->improve_skill( "parry",victim->query("con") );

	return 1;
}

void setup_ob(object me,object victim)
{
	object *inv;
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


		max1 = (int)max + random(max);

		if( victim->query("combat_exp",1) < 10000 ) max1/2;
		me->set_skill("dodge", max1);
		me->set_skill("parry", max1 );
		me->set_skill("force", max1);

		me->set("combat_exp", victim->query("combat_exp",1)+random(victim->query("combat_exp",1)/10));

		me->set("max_qi", victim->query("max_qi"));
		me->set("eff_qi", victim->query("max_qi"));
		me->set("max_jing", victim->query("max_jing"));
		me->set("eff_jing", victim->query("max_jing"));
		me->set("qi", me->query("max_qi"));
		me->set("jing", me->query("max_jing"));
		me->set("jiali", victim->query("jiali")*3/4);
		if ( victim->query("max_jingli") > 0 ) {
			me->set("max_jingli", victim->query("max_jingli"));
		}
		else me->set("max_jingli", 500);
		me->set("jingli", me->query("max_jingli"));

		me->set("no_sing", 1);
		me->set_temp("copied", 1);
		}
	}
}
