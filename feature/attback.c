//Cracked by Roath
// attack.c
// From ES2
// Modified by Xiang for XKX (12/15/95)

#include <ansi.h>
#include <dbase.h>
#include <origin.h>
#include <skill.h>

#define MAX_OPPONENT	4

static object *enemy = ({});
static string *killer = ({});

// prototypes

object *query_enemy() { return enemy; }
string *query_killer() { return killer; }

// This function returns 1 if we are fighting anyone (or with ob)
varargs int is_fighting(object ob)
{
	if( !ob ) return sizeof(enemy) > 0;

	return member_array(ob, enemy)!=-1;
}

// This function returns 1 if we are fighting anyone (or with ob)
varargs int is_killing(string id)
{
	if( !id ) return sizeof(killer) > 0;

	return member_array(id, killer)!=-1;
}

//This function starts fight between this_object() and ob
void fight_ob(object ob)
{
	if(!ob || ob==this_object()) return;

	set_heart_beat(1);

	if( member_array(ob, enemy)==-1 ) 
		enemy += ({ ob });
}

// This function starts killing between this_object() and ob
void kill_ob(object ob)
{
	// Marz added no_fight check here
	if (environment()->query("no_fight")) return;
	
	if( member_array(ob->query("id"), killer)==-1 )
		killer += ({ ob->query("id") });

	tell_object(ob, HIR "看起来" + this_object()->name() + "想杀死你！\n" NOR);

	fight_ob(ob);
}

void clean_up_enemy()
{
	if( sizeof(enemy) > 0 ) {
		for(int i=0; i<sizeof(enemy); i++) {
			if( !objectp(enemy[i])
			||	environment(enemy[i])!=environment()
			||	(!living(enemy[i]) && !is_killing(enemy[i]->query("id"))) )
				enemy[i] = 0;
		}
		enemy -= ({ 0 });
	}
}

// This function checks if the current opponent is available or
// select a new one.
object select_opponent()
{
	int which;

	if( !sizeof(enemy) ) return 0;

	which = random(MAX_OPPONENT);

	return which < sizeof(enemy) ? enemy[which] : enemy[0];
}

// Stop fighting ob.
int remove_enemy(object ob)
{
	if( is_killing(ob->query("id")) ) return 0;

	enemy -= ({ ob });
	return 1;
}

// Stop killing ob.
int remove_killer(object ob)
{
	if( is_killing(ob->query("id")) ) {
		killer -= ({ ob->query("id") });
		remove_enemy(ob);
		return 1;
	}

	return remove_enemy(ob);
}

// Stop all fighting, but killer remains.
void remove_all_enemy()
{
	for(int i=0; i<sizeof(enemy); i++) {
		// We ask our enemy to stop fight, but not nessessary to confirm
		// if the fight is succeffully stopped, bcz the fight will start
		// again if our enemy keeping call COMBAT_D->fight() on us.
		if( objectp(enemy[i]) ) enemy[i]->remove_enemy(this_object());
		enemy[i] = 0;;
	}

	enemy = ({});
}

// Stop all fighting and killing.
void remove_all_killer()
{
	killer = ({});
	enemy -= ({ 0 });

	for(int i=0; i<sizeof(enemy); i++)
		if( enemy[i]->remove_killer(this_object()) )
			enemy[i] = 0;;

	enemy -= ({ 0 });
}

// reset_action()
//
// This function serves as a interface of F_ATTACK and wielded, worn objects.
// When the living's fighting action need update, call this function.
//
void reset_action()
{
	object me,ob;
	mapping prepare;
	string type, skill;

        me = this_object();
	prepare = query_skill_prepare();
	
	if( ob = query_temp("weapon") ) type = ob->query("skill_type");
	else if ( sizeof(prepare) == 0)	type = "unarmed";
	else if ( sizeof(prepare) == 1)	type = (keys(prepare))[0];
	else if ( sizeof(prepare) == 2)	
		type = (keys(prepare))[query_temp("action_flag")];

	if( stringp(skill = query_skill_mapped(type)) ) {
		// If using a mapped skill, call the skill daemon.
                if ( ob )
	         	set("actions", (: call_other, SKILL_D(skill), "query_action", me, ob :) );
                else
                        set("actions", (: call_other, SKILL_D(skill), "query_action" :) );
	} else {
		// Else, let weapon handle it.
		if( ob ) set("actions", ob->query("actions",1) );
		else set("actions", query("default_actions",1) );
	}
}

// This is called in heart_beat() to perform attack action.
int attack()
{
	object opponent;

	clean_up_enemy();

	opponent = select_opponent();
	if( objectp(opponent) ) {
		set_temp("last_opponent", opponent);
		if( !this_object()->query_temp("yield") )
		COMBAT_D->fight(this_object(), opponent);
		return 1;
	} else
		return 0;
}

//
// init() - called by MudOS when another object is moved to us.
//
void init()
{
	object ob;
	string vendetta_mark;

	// We check these conditions here prior to handle auto fights. Although
	// most of these conditions are checked again in COMBAT_D's auto_fight()
	// function, these check reduces lots of possible failure in the call_out
	// launched by auto_fight() and saves some overhead.
	if(	is_fighting()
	||	!living(this_object())
	||	!(ob = this_player()) 
	||	environment(ob)!=environment()
	||	!living(ob)
	||	ob->query("linkdead") )
		return;

	// Now start check the auto fight cases.
	if( userp(ob) && is_killing(ob->query("id")) ) {
		COMBAT_D->auto_fight(this_object(), ob, "hatred");
		return;
	} else if( stringp(vendetta_mark = query("vendetta_mark"))
	&& ob->query("vendetta/" + vendetta_mark) ) {
		COMBAT_D->auto_fight(this_object(), ob, "vendetta");
		return;
	} else if( userp(ob) && (string)query("attitude")=="aggressive" ) {
		COMBAT_D->auto_fight(this_object(), ob, "aggressive");
		return;
	} 
}
