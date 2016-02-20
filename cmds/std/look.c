//Cracked by Roath
// look.c
// modified by sdong for biaoche, 12/23/98

#include <room.h>
#include <ansi.h>

inherit F_CLEAN_UP;

int look_room(object me, object env);
int look_item(object me, object obj);
int look_living(object me, object obj);
int look_room_item(object me, string arg);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object obj;
	int result;

	if( !arg ) result = look_room(me, environment(me));
	else if( (obj = present(arg, me)) || (obj = present(arg, environment(me)))) {
		if( obj->is_character() ) result = look_living(me, obj);
		else result = look_item(me, obj);
	} else result = look_room_item(me, arg);

	return result;
}

int look_room(object me, object env)
{
	int i;
	object *inv;
	mapping exits;
	string str, *dirs;

	if( !env ) {
		write("你的四周灰蒙蒙地一片，什么也没有。\n");
		return 1;
	}
	str = sprintf( "%s - %s\n    %s%s",
		env->query("short"),
		wizardp(me)? file_name(env): "",
		env->query("long"),
		env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );

	if( mapp(exits = env->query("exits")) ) {
		dirs = keys(exits);
		for(i=0; i<sizeof(dirs); i++)
			if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
				dirs[i] = 0;
		dirs -= ({ 0 });
		if( sizeof(dirs)==0 )
			str += "    这里没有任何明显的出路。\n";
		else if( sizeof(dirs)==1 )
			str += "    这里唯一的出口是 " + BOLD + dirs[0] + NOR + "。\n";
		else
			str += sprintf("    这里明显的出口是 " + BOLD + "%s" + NOR + " 和 " + BOLD + "%s" + NOR + "。\n",
				implode(dirs[0..sizeof(dirs)-2], "、"), dirs[sizeof(dirs)-1]);
	}
//	str += env->door_description();

	inv = all_inventory(env);
	for(i=0; i<sizeof(inv); i++) {
		if( inv[i]==me ) continue;
		if( !me->visible(inv[i]) ) continue;
		if( objectp(inv[i]->query("rider")) ) continue;
		else inv[i]->delete("rider");


		if( objectp(inv[i]->query("rided")) ) {
			str += "  " + inv[i]->short() + "骑在" +
			(inv[i]->query("rided"))->name() + "上";
		if( stringp(inv[i]->query_temp("exit_blocked")))
								str += "挡着往"+inv[i]->query_temp("exit_blocked")+
								"去的路";
			str += "\n";
		}
		else {
			if (stringp(inv[i]->query_temp("exit_blocked")))
			str += "  " + inv[i]->short() + "挡着往" + inv[i]->query_temp("exit_blocked")
				+"去的路\n";
			else if( inv[i]->query_temp("riding") ) {
				str += "  " + inv[i]->short() + "坐在镖车上\n";
			}
			else
				str += "  " + inv[i]->short() + "\n";
			inv[i]->delete("rided");
		}
	}


	write(str);
	return 1;
}

int look_item(object me, object obj)
{
	mixed *inv;

	write(obj->long());
	inv = all_inventory(obj);
	if( sizeof(inv) ) {
		inv = map_array(inv, "inventory_look", this_object() );
		message("vision", sprintf("里面有：\n  %s\n",
			implode(inv, "\n  ") ), me);
	}
	return 1;
}

int look_living(object me, object obj)
{
	string str, limb_status, pro;
	mixed *inv;
	mapping my_fam, fam;

	if(( me!=obj )&& (environment(me) == environment(obj))) {
	  if ( !wizardp(me) || (wizardp(me) && !wizardp(obj) && !me->query("env/invisibility")) )
		message("vision", me->name() + "正盯著你看，不知道打些什么主意。\n", obj);
	}

	str = obj->long();

	pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(obj->query("gender"));

	if( objectp(obj->query("rided")) ) 
		str += sprintf(pro +  "骑在" + (obj->query("rided"))->name() + "上。\n");

	if( (string)obj->query("race")=="人类"
	&&	intp(obj->query("age")) )
		str += sprintf("%s看起来约%s多岁。\n", pro, 
			chinese_number(
			(obj->query("age")-SKILL_D("beauty")->reduce_age(obj)) / 10 * 10));

	// If we both has family, check if we have any relations.
	if( obj!=me
	&&	mapp(fam = obj->query("family"))
	&&	environment(me) == environment(obj)
	&&	mapp(my_fam = me->query("family")) 
	&&	fam["family_name"] == my_fam["family_name"] ) {
	
		if( fam["generation"]==my_fam["generation"] ) {
			if( (string)obj->query("gender") == "男性" ||
				(string)obj->query("gender") == "无性")
				str += sprintf( pro + "是你的%s%s。\n",
					my_fam["master_id"] == fam["master_id"] ? "": "同门",
					my_fam["enter_time"] > fam["enter_time"] ? "师兄": "师弟");
			else
				str += sprintf( pro + "是你的%s%s。\n",
					my_fam["master_id"] == fam["master_id"] ? "": "同门",
					my_fam["enter_time"] > fam["enter_time"] ? "师姐": "师妹");
		} else if( fam["generation"] < my_fam["generation"] ) {
			if( my_fam["master_id"] == obj->query("id") )
				str += pro + "是你的师父。\n";
			else if( my_fam["generation"] - fam["generation"] > 1 )
				str += pro + "是你的同门长辈。\n";
			else if( fam["enter_time"] < my_fam["enter_time"] )
				str += pro + "是你的师伯。\n";
			else
				str += pro + "是你的师叔。\n";
		} else {
			if( fam["generation"] - my_fam["generation"] > 1 )
				str += pro + "是你的同门晚辈。\n";
			else if( fam["master_id"] == me->query("id") )
				str += pro + "是你的弟子。\n";
			else
				str += pro + "是你的师侄。\n";
		}
	}

	if( obj->is_spouse_of(me) )
		str += pro + "是你的" + me->query("spouse/title") + "。\n";
		
	if( obj->query("max_qi") )
		str += pro + COMBAT_D->eff_status_msg((int)obj->query("eff_qi") * 100 / (int)obj->query("max_qi")) + "\n";

	inv = all_inventory(obj);
	if( sizeof(inv) ) {
		inv = map_array(inv, "inventory_look", this_object(), obj->is_corpse()? 0 : 1 );
		inv -= ({ 0 });
		if( sizeof(inv) )
			str += sprintf( obj->is_corpse() ? "%s的遗物有：\n%s\n" : "%s身上带著：\n%s\n",
				pro, implode(inv, "\n") );
	}

	message("vision", str, me);

	if( obj!=me && !obj->is_spouse_of(me) 
	&&	living(obj)
	&&	random(-(int)obj->query("shen")) > (int)me->query("int") * 10 ) {
		write( obj->name() + "突然转过头来瞪你一眼。\n");
		COMBAT_D->auto_fight(obj, me, "berserk");
	}

	return 1;
}

string inventory_look(object obj, int flag)
{
	string str;

	str = obj->short();
	if( obj->query("embedded") )
		str = HIR "  √" NOR + str;
	else if( obj->query("equipped") )
		str = HIC "  □" NOR + str;
	else if( !flag )
		str = "    " + str;
	else
		return 0;

	return str;
}

int look_room_item(object me, string arg)
{
	object env;
	mapping item, exits;

	if( !objectp(env = environment(me)) )
		return notify_fail("这里只有灰蒙蒙地一片，什么也没有。\n");
	if( mapp(item = env->query("item_desc")) && !undefinedp(item[arg]) ) {
		if( stringp(item[arg]) )
			write(item[arg]);
		else if( functionp(item[arg]) )
			write((string)(*item[arg])(me));
			
		return 1;
	}
	if( mapp(exits = env->query("exits")) && !undefinedp(exits[arg]) ) {
		if( objectp(env = find_object(exits[arg])) )
			look_room(me, env);
		else {
			call_other(exits[arg], "???");
			look_room(me, find_object(exits[arg]));
		}
		return 1;
	}
	return notify_fail("你要看什么？\n");
}

int help (object me)
{
	write(@HELP
指令格式: look [<物品>|<生物>|<方向>]
 
这个指令让你查看你所在的环境、某件物品、生物、或是方向。
 
HELP
);
	return 1;
}
