//Cracked by Roath
// mu-ren.c 铜人

#include <combat.h>

inherit NPC;
inherit F_MASTER;
inherit F_CLEAN_UP;
inherit F_UNIQUE;
inherit F_SAVE;

void killing(object, object, int);
int do_kill(string);
int do_tune(string);
int do_fight(string);

void create()
{
	set_name("铜人", ({ "tong ren", "tong", "copper man", "copper" }) );
	set("gender", "男性" );
	set("age", 30);
	set("long", "一个练功用的比武铜人，制作精巧，如同真人一般。\n");
	set("attitude", "heroism");

	set("str", 25);
	set("cor", 25);
	set("cps", 25);
	set("int", 25);

	set("max_qi", 300);
	set("eff_qi", 300);
	set("qi", 300);
	set("max_jing", 100);
	set("jing", 100);
	set("neili", 300);
	set("max_neili", 300);
	set("jiali", 10);
	set("shen_type", 0);

	set("combat_exp", 50000);

	set_skill("force", 30); 
	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);

	set_weight(1000000);
	set("fight_times", 10);	

	setup();
        
}

void init()
{
	::init();
	add_action("do_kill", "kill");
	add_action("do_tune", "tune");
	add_action("do_fight", "fight");
	add_action("do_fight", "bihua");
	add_action("do_halt", "halt");
}

int do_kill(string arg)
{
	object ob = this_player();
	object me = this_object();
	
	if( present(arg, environment(me)) != me ) return 0;

	tell_object(ob, "你想杀铜人？！ 莫非头脑有点不正常了？！\n");
	return 1;
}

int do_halt()
{
	object ob = this_player();
	object me = this_object();
	
//	if(me->is_fighting(ob)) {
		me->set("fight_times", 0);
		remove_call_out("killing");
		return 1;
//	}

	return 0;
}

int do_tune(string arg)
{
	int times;
	sscanf(arg, "%d", times);

	this_object()->set("fight_times", times);

	message_vision("$N将铜人攻击次数设为" + chinese_number(times) + "次。\n", this_player());
	return 1;
}

int do_fight(string arg)
{
	object me, ob, *inv;
	mapping hp_status, skill_status, map_status, prepare_status;
	string *sname, *mname, *pname;
	int i, temp;

	me = this_object();
	ob = this_player();

	if( !arg || arg == "" ) return 0;

	if( me->is_fighting() ) return 0;

	if( me != present(arg, environment(me)) ) return 0;

/* delete and copy skills */

	if ( mapp(skill_status = me->query_skills()) ) {
		skill_status = me->query_skills();
		sname  = keys(skill_status);

		temp = sizeof(skill_status);
		for(i=0; i<temp; i++) {
			me->delete_skill(sname[i]);
		}
	}

	if ( mapp(skill_status = ob->query_skills()) ) {
		skill_status = ob->query_skills();
		sname  = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++) {
			me->set_skill(sname[i], skill_status[sname[i]]);
		}
	}
	
/* delete and copy skill maps */

	if ( mapp(map_status = me->query_skill_map()) ) {
		mname  = keys(map_status);

		temp = sizeof(map_status);
		for(i=0; i<temp; i++) {
			me->map_skill(mname[i]);
		}
	}

	if ( mapp(map_status = ob->query_skill_map()) ) {
		mname  = keys(map_status);

		for(i=0; i<sizeof(map_status); i++) {
			me->map_skill(mname[i], map_status[mname[i]]);
		}
	}
	
/* delete and copy skill prepares */

	if ( mapp(prepare_status = me->query_skill_prepare()) ) {
		pname  = keys(prepare_status);

		temp = sizeof(prepare_status);
		for(i=0; i<temp; i++) {
			me->prepare_skill(pname[i]);
		}
	}

	if ( mapp(prepare_status = ob->query_skill_prepare()) ) {
		pname  = keys(prepare_status);

		for(i=0; i<sizeof(prepare_status); i++) {
			me->prepare_skill(pname[i], prepare_status[pname[i]]);
		}
	}

/* unwield and remove weapon & armor */

	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++) {
		destruct(inv[i]);
	}
	set("weapon", 0);
	set("armor", 0);

/* wield and wear weapon & armor */

	inv = all_inventory(ob);
	for(i=0; i<sizeof(inv); i++) {
		if( inv[i]->query("weapon_prop/damage") > 100 
		||  inv[i]->query("armor_prop/armor") > 100 ) continue;

		if( inv[i]->query("weapon_prop") &&  inv[i]->query("equipped") ) {
			carry_object(base_name(inv[i]))->wield();
			me->set("weapon", base_name(inv[i]));
		}
		else if( inv[i]->query("armor_prop") &&  inv[i]->query("equipped") ) {
			carry_object(base_name(inv[i]))->wear();
			me->set("armor", base_name(inv[i]));
		}
	}

/* copy entire dbase values */

	hp_status = ob->query_entire_dbase();

		me->set("str", hp_status["str"]);
		me->set("int", hp_status["int"]);
		me->set("con", hp_status["con"]);
		me->set("dex", hp_status["dex"]);
		me->set("age", hp_status["age"]);

		me->set("max_qi",    hp_status["max_qi"]);
		me->set("eff_qi",    hp_status["eff_qi"]);
		me->set("qi",        hp_status["qi"]);
		me->set("max_jing",  hp_status["max_jing"]);
		me->set("eff_jing",  hp_status["eff_jing"]);
		me->set("jing",      hp_status["jing"]);
		me->set("max_jingli",hp_status["max_jingli"]);
		me->set("eff_jingli",hp_status["eff_jingli"]);
		me->set("jingli",    hp_status["jingli"]);
		me->set("max_neili", hp_status["max_neili"]);
		me->set("neili",     hp_status["neili"]);
		me->set("jiali",     hp_status["jiali"]);
		me->set("gender",    hp_status["gender"]);
		me->set("combat_exp",hp_status["combat_exp"]);
		me->set("death_times",hp_status["death_times"]);
		me->set("death_count",hp_status["death_count"]);


	message_vision("铜人一合掌，开始进攻！\n\n", me);

	remove_call_out("killing");
	call_out("killing", 1, me, ob, 0);	

	return 1;
}

void killing(object me, object ob, int count)
{
	if( environment(me) != environment(ob) ) return;

	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), TYPE_REGULAR);
	COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), TYPE_REGULAR);

	if( ob->query("qi") >= 10 && count <= me->query("fight_times")) {
		count ++;
		call_out("killing", 0, me, ob, count);
	}
	else return;
}
