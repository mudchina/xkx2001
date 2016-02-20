//Cracked by Roath
// damage.c

#include <ansi.h>
#include <dbase.h>
#include <login.h>
#include <move.h>

int ghost = 0;

int is_ghost() { return ghost; }

varargs int receive_damage(string type, int damage, mixed who)
{
	int val;

	if( damage < 0 ) error("F_DAMAGE: 伤害值为负值。\n");
	if( type!="jing" && type!="qi" && type!="jingli")
		error("F_DAMAGE: 伤害种类错误( 只能是 jing, qi, jingli 其中之一 )。\n");

	set_temp("last_damage_from", who);
	
	//cyz&kitten 99/05/08
	
	if(living(this_object()) && objectp(who) && userp(who)) 
		set_temp("last_eff_damage_from", who->query("id"));
	

	val = (int)query(type) - damage;

	if( val >= 0 ) set(type, val);
	else set( type, -1 );

	set_heart_beat(1);

	return damage;
}

varargs int receive_wound(string type, int damage, mixed who)
{
	int val;

	if( damage < 0 ) error("F_DAMAGE: 伤害值为负值。\n");
	if( type!="jing" && type!="qi" )
		error("F_DAMAGE: 伤害种类错误( 只能是 jing, qi 其中之一 )。\n");

	set_temp("last_damage_from", who);
	
	
	if(living(this_object()) && objectp(who) && userp(who)) 
		set_temp("last_eff_damage_from", who->query("id"));
	
	val = (int)query("eff_" + type) - damage;

	if( val >= 0 ) set("eff_" + type, val);
	else {
		set( "eff_" + type, -1 );
		val = -1;
	}

	if( (int)query(type) > val ) set(type, val);

	set_heart_beat(1);

	return damage;
}

int receive_heal(string type, int heal)
{
	int val;

	if( heal < 0 ) error("F_DAMAGE: 恢复值为负值。\n");
	if( type!="jing" && type!="qi" && type!="jingli")
		error("F_DAMAGE: 恢复种类错误( 只能是 jing, qi 其中之一 )。\n");

	val = (int)query(type) + heal;

	if( val > (int)query("eff_" + type) && type!="jingli" ) set(type, (int)query("eff_" + type));
	else if( val > (int)query("max_" + type) && type=="jingli" ) set(type, (int)query("max_" + type));
	else set( type, val );

	return heal;
}

int receive_curing(string type, int heal)
{
	int max, val;

	if( heal < 0 ) error("F_DAMAGE: 恢复值为负值。\n");
	if( type!="jing" && type!="qi" )
		error("F_DAMAGE: 恢复种类错误( 只能是 jing, qi 其中之一 )。\n");

	val = (int)query("eff_" + type);
	max = (int)query("max_" + type);

	if( val + heal > max ) {
		set("eff_" + type, max);
		return max - val;
	} else {
		set( "eff_" + type, val + heal);
		return heal;
	}
}

void unconcious()
{
	object defeater;

	if( !living(this_object()) ) return;
	if( wizardp(this_object()) && query("env/immortal") ) return;
	
	if( objectp(defeater = query_temp("last_damage_from")) )
	{
		COMBAT_D->winner_reward(defeater, this_object());
		// cyz&kitten 99/05/08 to check who fainted victim
		if(userp(defeater))
		set_temp("last_fainted_from", defeater->query("id"));
	}

	this_object()->remove_all_enemy();
// xuy, interrupt all dazuo, jingzuo etc.
	this_object()->interrupt_me();

	this_object()->dismiss_team();
	message("system", HIR "\n你的眼前一黑，接著什么也不知道了....\n\n" NOR,
		this_object());
	this_object()->disable_player(" <昏迷不醒>");
	set("jing", 0);
	set("qi", 0);
	set("jingli", 0);
	set_temp("block_msg/all", 1);
	COMBAT_D->announce(this_object(), "unconcious");

	call_out("revive", random(100 - query("con")) + 30);
}

varargs void revive(int quiet)
{
	remove_call_out("revive");
	while( environment()->is_character() )
		this_object()->move(environment(environment()));
	this_object()->enable_player();
	if( !quiet ) {
		COMBAT_D->announce(this_object(), "revive");
		set_temp("block_msg/all", 0);
		message("system", HIY "\n慢慢地你终于又有了知觉....\n\n" NOR,
			this_object());
	} else
		set_temp("block_msg/all", 0);
}

void die()
{
	object corpse, rum_ob, me;
	mixed killer;
	int i;

    me = this_object();
	if( environment()->query("no_death") && userp(this_object()) )
		{

//			if ( !objectp(rum_ob = find_object("/d/huashan/npc/referee")) )
//				rum_ob = load_object("/d/huashan/npc/referee");

//			killer = query_temp("last_damage_from");

//			if ( stringp(killer) )
//				CHANNEL_D->do_channel(rum_ob, "chat",
//					sprintf("%s被" + killer + "干掉了。", this_object()->name(1)));
//			else
//				CHANNEL_D->do_channel(rum_ob, "rumor",
//					sprintf("%s被干掉了。", this_object()->name(1)));
			unconcious();
			remove_call_out("revive");

			return;
		}

	if( !living(this_object()) ) revive(1);
	if( wizardp(this_object()) && query("env/immortal") ) return;


	// Clear all the conditions by death.
	this_object()->clear_condition();
	this_object()->delete("poisoner");

	COMBAT_D->announce(this_object(), "dead");

	if ( userp(this_object()) && !environment(this_object())->query("no_death"))
		COMBAT_D->death_penalty(this_object());

	if( objectp(killer = query_temp("last_damage_from"))){
		set_temp("my_killer", killer->query("id"));
		COMBAT_D->killer_reward(killer, this_object());
	} else  if (userp(this_object()))
	{
	if ( !objectp(rum_ob = find_object("/d/city/npc/aqingsao")) )
		rum_ob = load_object("/d/city/npc/aqingsao");

	if ( stringp(killer) )
		CHANNEL_D->do_channel(rum_ob, "rumor",
			sprintf("%s" + killer + "。", this_object()->name(1)));
	else
		CHANNEL_D->do_channel(rum_ob, "rumor",
			sprintf("%s莫名其妙地死了。", this_object()->name(1)));
	}

    // log for death reason
    if ( userp(this_object()) ) {
       if (stringp(query_temp("last_eff_damage_from")) ) {
           log_file("PKILL_DATA", sprintf("%s(%s) 被 %s 杀死了(PlayerKill) on %s。\n", me->query("name"), 
             getuid(me), query_temp("last_eff_damage_from"), ctime(time()) ));
           log_file("PLAYER_DEATH", sprintf("%s(%s) 被 %s 杀死了(PlayerKill) on %s。\n", me->query("name"), 
             getuid(me), query_temp("last_eff_damage_from"), ctime(time()) ));
       }
       else if (objectp(killer)){
           log_file("PLAYER_DEATH", sprintf("%s(%s) 被 %s 杀死了 on %s。\n", me->query("name"), 
             getuid(me), killer->name(), ctime(time()) ));
       }
       else if (stringp(killer)){
           log_file("PLAYER_DEATH", sprintf("%s(%s) died from %s on %s。\n", me->query("name"), 
             getuid(me), query_temp("last_damage_from"), ctime(time()) ));
       }
    }
	
    if( ( !environment()->query("no_death") || !userp(this_object()) ) 
	 && objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
		corpse->move(environment());

	this_object()->remove_all_killer();
	all_inventory(environment())->remove_killer(this_object());

	if( userp(this_object()) ) {
		if (this_object()->is_busy())
			this_object()->interrupt_me();
		set("jing", 1);	set("eff_jing", 1);
		set("qi", 1);	set("eff_qi", 1);
		set("jingli", 1);
		if (environment(this_object())->query("no_death")) {
			set("eff_jing", query("max_jing"));
			set("eff_qi", query("max_qi"));
			return;
		}
		this_object()->dismiss_team();
		this_object()->save();
		ghost = 1;
		this_object()->move(DEATH_ROOM);
		DEATH_ROOM->start_death(this_object());
		MARRY_D->break_marriage(this_object()); // added by Zhuang@XKX
		if( this_object()->query("family/master_id")=="feng qingyang" ) 							CHAR_D->break_relation(this_object()); //added by Qfy
	} else
		destruct(this_object());
}

void reincarnate()
{
	ghost = 0;
	set("jing", query("max_jing"));
	set("qi", query("max_qi"));
	set("eff_jing", query("max_jing"));
	set("eff_qi", query("max_qi"));
	set("jingli", query("max_jingli"));
	set("neili", query("max_neili"));
}

int max_food_capacity() { return query_weight() / 200; }

int max_water_capacity() { return query_weight() / 200; }

int heal_up()
{
	int update_flag, i;
	mapping my;

//	if( this_object()->is_fighting() ) return -1;

	update_flag = 0;

	my = query_entire_dbase();

	if( my["water"] > 0 ) { my["water"] -= 1; update_flag++; }
	if( my["food"] > 0 ) { my["food"] -= 1; update_flag++; }

	if( my["water"] < 1 && userp(this_object()) ) return update_flag;
	if( my["food"] < 1 && userp(this_object()) ) return update_flag;
	

	if( this_object()->is_fighting() )
		my["jing"] += my["con"] / 9 + my["max_jingli"] / 30;
	else
		my["jing"] += my["con"] / 3 + my["max_jingli"] / 10;

	if( my["jing"] >= my["eff_jing"] ) {
		my["jing"] = my["eff_jing"];
		if( my["eff_jing"] < my["max_jing"] ) { my["eff_jing"] ++; update_flag++; }
	} else update_flag++;


	if( this_object()->is_fighting() )
		my["qi"] += my["con"] / 9 + my["max_neili"] / 30;
	else
		my["qi"] += my["con"] / 3 + my["max_neili"] / 10;

	if( my["qi"] >= my["eff_qi"] ) {
		my["qi"] = my["eff_qi"];
		if( my["eff_qi"] < my["max_qi"] ) { my["eff_qi"] ++; update_flag++; }
	} else update_flag++;


	if( my["max_jingli"] && my["jingli"] < my["max_jingli"] ) {
		if( this_object()->is_fighting() )
			my["jingli"] +=  (my["str"] + my["dex"]) / 12;
		else
			my["jingli"] +=  (my["str"] + my["dex"]) / 4;

		if( my["jingli"] > my["max_jingli"]*2 ) my["jingli"] = my["max_jingli"]*2;
		update_flag++;
	}

	if( my["max_neili"] && my["neili"] < my["max_neili"] ) {
		if( this_object()->is_fighting() )
			my["neili"] += (int)this_object()->query_skill("force", 1) / 6;
		else
			my["neili"] += (int)this_object()->query_skill("force", 1) / 2;

		if( my["neili"] > my["max_neili"] ) my["neili"] = my["max_neili"];
		update_flag++;
	}

	return update_flag;
}
