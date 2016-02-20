//Cracked by Kafei
// emoted.c

#include <ansi.h>
#include <mudlib.h>

inherit F_DBASE;
inherit F_SAVE;

mapping emote;

//	The emote mapping contains the data base of emote definitions. Each emote
//	is defined in a sub-mapping with the following structure:
//
//	myself	- the message emoter will see
//	target	- the message the target will see when targeted
//	others	- the message others will see when no argument.
//
//	The emote mapping is indexed with the emote 'pattern' instead of emote
//	verb. For example, typing "smile" without argument will cause the daemon
//	search the emote mapping with "smile" as key, and typing "smile someone"
//	will cause the daemon search the emote mapping with "smile $" pattern as
//	the key, while $ means one argument.
//
//	In the message string, the following substitutions will be applied before
//	sending the messages:
//
//	$N		- name of emoter
//	$n		- name of target
//	$P		- pronoun of emoter
//	$p		- pronoun of target
//
//	Original by Annihilator@ESII (11/09/94)
//      $C              - very close call of emoter
//      $c              - close call of target
//      $R              - respect calling of target
//      $r              - rude calling of target
//      $S              - self calling of emoter
//      $s              - self-rude calling of emoter
//      aboved added by Xiang@XKX


void create()
{
	seteuid(ROOT_UID);
	if( !restore() && !mapp(emote) )
		emote = ([]);
}

int remove()
{
	save();
	return 1;
}

string query_save_file() { return DATA_DIR + "emoted"; }

// strip ansi color from string.  by xuy@xkx
string normal_color(string arg)
{
	int i, j;
	string str = "";
	for (i = 0; i < strlen(arg); i++) {
		if (arg[i..i] == ESC) 
			while (++i) {
				if ( arg[i..i] == "m" ) break;
			}
		else
			str += arg[i..i];
	}
	return str;
}
		
// command_hook() of F_COMMAND call this as an alternate command processor.
// CHANNEL_D also calls this to get emote message.
//
// channel_emote == 1 -- "chat" channel
//               == 2 -- "rumor" channel
varargs mixed do_emote(object me, string verb, string arg, int channel_emote)
{
	string str, my_gender, target_gender, msg_postfix, myname, targetname;
	object target;

	if( !environment(me) ) return 0;

	if ( !mapp(emote) || undefinedp(emote[verb]) ) return 0;

	if(channel_emote == 2 || (!channel_emote && wizardp(me) && me->query("env/invisibility")) )
		myname = "某人";
	else if(channel_emote == 3) 
		myname = sprintf("%s(%s@%s)", me->name(), capitalize(me->query("id")), INTERMUD_MUD_NAME);
        else
                myname = me->name();
			
	// Determine the pattern to be searched and the target.
	if ( stringp(arg) && arg != "" ) {
		target = present(arg, environment(me));

		if(!objectp(target)) {
			// If not channel emote, only search target in our environment.
			if(!channel_emote) return 0;
			target = find_player(arg);
			if( !objectp(target) ) return 0;
		}
		
		if( !target->is_character() || !me->visible(target) )
			return notify_fail("你要对谁做这个动作？\n"); 

		target_gender = target->query("gender");
		if( target==me ) {
			msg_postfix = "_self";
			target = 0;
		} else msg_postfix = "_target";
	} else msg_postfix = "";

	my_gender = me->query("gender");
	if( objectp(target) ) {
		if(channel_emote == 3) 
			targetname = sprintf("%s(%s@%s)", target->name(), capitalize(target->query("id")), INTERMUD_MUD_NAME);
        	else
                	targetname = target->name();
	}

	if( stringp(str = emote[verb]["myself" + msg_postfix]) ) {
		str = replace_string(str, "$N", myname);
		str = replace_string(str, "$P", gender_self(my_gender));
                str = replace_string(str, "$S", RANK_D->query_self(me));
                str = replace_string(str, "$s", RANK_D->query_self_rude(me));
		if( objectp(target) ) {
       	        	str = replace_string(str, "$C", RANK_D->query_self_close(target));
                	str = replace_string(str, "$c", RANK_D->query_close(target));
                	str = replace_string(str, "$R", RANK_D->query_respect(target));
                	str = replace_string(str, "$r", RANK_D->query_rude(target));
			str = replace_string(str, "$n", targetname);
			str = replace_string(str, "$p", gender_pronoun(target_gender));
		}
		if( !channel_emote ) message("emote", CYN + normal_color(str) + NOR, me);
	}

	if( objectp(target) && stringp(str = emote[verb]["target"]) ) {
		str = replace_string(str, "$N", myname);
		str = replace_string(str, "$P", gender_pronoun(my_gender));
                str = replace_string(str, "$S", RANK_D->query_self(me));
                str = replace_string(str, "$s", RANK_D->query_self_rude(me));
                str = replace_string(str, "$C", RANK_D->query_self_close(target));
                str = replace_string(str, "$c", RANK_D->query_close(target));
                str = replace_string(str, "$R", RANK_D->query_respect(target));
                str = replace_string(str, "$r", RANK_D->query_rude(target));
		str = replace_string(str, "$n", targetname);
		str = replace_string(str, "$p", gender_self(target_gender));
		if( !channel_emote ) message("emote", CYN + normal_color(str) + NOR, target);
	}

	if( stringp(str = emote[verb]["others"+msg_postfix]) ) {
		str = replace_string(str, "$N", myname);
		str = replace_string(str, "$P", gender_pronoun(my_gender));
                str = replace_string(str, "$S", RANK_D->query_self(me));
                str = replace_string(str, "$s", RANK_D->query_self_rude(me));
		if( objectp(target) ) {
                	str = replace_string(str, "$C", RANK_D->query_self_close(target));
                	str = replace_string(str, "$c", RANK_D->query_close(target));
                	str = replace_string(str, "$R", RANK_D->query_respect(target));
                	str = replace_string(str, "$r", RANK_D->query_rude(target));
			str = replace_string(str, "$n", targetname);
			str = replace_string(str, "$p", gender_pronoun(target_gender));
		}
		if( !channel_emote ) message("emote", CYN + normal_color(str) + NOR, environment(me), ({me, target}));
		else return normal_color(str);
	}

	// Let NPC know we are doing emote on him.
	if( objectp(target) ) target->relay_emote(me, verb);

	return 1;
}

// me is in format of name:gender:rank_self:rank_self_rude:age:mud_age
varargs mixed do_intermud_emote(string myinfo, string verb, string targetid)
{
	int mud_age, age;
	string str, name, gender, self, self_rude;
	object target;

	if(!mapp(emote) || undefinedp(emote[verb]) ||
	   !targetid || !(target = find_player(targetid)) ) return 0;

	if( sscanf(myinfo, "%s:%s:%s:%s:%d:%d", 
			name, gender, self, self_rude, age, mud_age)!=6)
		return;

	set("gender", gender);
	set("age", age);
	set("mud_age", mud_age);

	if( stringp(str = emote[verb]["others_target"]) ) {
                str = replace_string(str, "$N", name);
                str = replace_string(str, "$P", gender_pronoun(gender));
                str = replace_string(str, "$S", self);
                str = replace_string(str, "$s", self_rude);
                str = replace_string(str, "$C", RANK_D->query_self_close(target));
                str = replace_string(str, "$c", RANK_D->query_close(target));
                str = replace_string(str, "$R", RANK_D->query_respect(target));
                str = replace_string(str, "$r", RANK_D->query_rude(target));
                str = replace_string(str, "$n", sprintf("%s(%s@%s)", target->name(), capitalize(target->query("id")), INTERMUD_MUD_NAME));
                str = replace_string(str, "$p", gender_pronoun(target->query("gender")));
        }
	return normal_color(str);
}
		
		

int set_emote(string pattern, mapping def)
{
	emote[pattern] = def;
	save();
	return 1;
}

int delete_emote(string pattern)
{
	map_delete(emote, pattern);
	save();
	return 1;
}

mapping query_emote(string pattern)
{
	if( !undefinedp(emote[pattern]) ) return emote[pattern];
	else return ([]);
}

string *query_all_emote()
{
	return keys(emote);
}
