//Cracked by Roath
// user.c
// Note: There has been a bug for long time: when npc got killed, npc's huanying
//			will stay forever. To fix this, let huanying destruct itself after a period
//       -Sdong, 2/8/99

#include <ansi.h>
#include <origin.h>
#include <user.h>

inherit CHARACTER;
inherit F_SAVE;

void create()
{
	object me = this_object();
	::create();
	set_name("»ÃÓ°", ({ "user huanying" }) );
	set("env/invisibility", 10);
	set("env/wimpy", 0);
	call_out("destruct_me",90+random(60),me);
}

void destruct_me(object me)
{
   if (me) destruct(me);
}

void init()
{
	object me = this_object();

	if ( !me->query_temp("created") ) {
				 me->set_temp("created", 1);
	}
}

string query_save_file()
{
	string id;

	id = query("master_id", 1);
	if( !stringp(id) ) return 0;
	return sprintf(DATA_DIR "user/%c/%s", id[0], id);
}

varargs void start_busy(mixed new_busy, mixed new_interrupt)
{
	object player = this_object()->query_temp("yanxing/huanying");
	if (objectp(player)) {
		if(player->is_busy()) 
			::start_busy(player->query_busy());
		return;
	}
	::start_busy(new_busy, new_interrupt);
}

/*
varargs int receive_wound(string type, int damage, mixed who)
{	
	return 0;
}
*/

/*
varargs int receive_damage(string type, int damage, mixed who)
{	
	return 0;
}
*/

void die()
{
	object me = this_object();
	//disable_commands();
	call_out("destruct_me",1,me);
}


void unconcious()
{
	object me = this_object();
	call_out("destruct_me",1,me);
	//disable_commands();
}

int remove_enemy(object ob)
{
	object player = this_object()->query_temp("yanxing/huanying");
        if (objectp(player))
		player->remove_enemy(ob);
	if (ob) ob->remove_enemy(player);
	return ::remove_enemy(ob);
}

int attack()
{
	int ret;
	object weapon, fakeweapon, opp;
	object player = this_object()->query_temp("yanxing/huanying");
	if (objectp(player) && player->is_fighting()) {
		weapon = player->query_temp("weapon");
		if (!weapon || weapon->query("skill_type") != "blade")
			return 0;
		if (!this_object()->query_temp("weapon")) {
			fakeweapon = weapon->clone();
			fakeweapon->move(this_object());
			fakeweapon->wield();
		}
		ret = ::attack();
		opp = this_object()->query_temp("last_opponent");
		if (objectp(opp) && opp->query_temp("last_damage_from") == this_object())
			opp->set_temp("last_damage_from", player);
		return ret;
	}
	::remove_all_enemy();
	return 0;
}
