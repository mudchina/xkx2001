//Cracked by Roath
// alias.c
// From ES2
// Marz added flood detection on (07/05/96)
#pragma save_binary

#include <ansi.h>

#define MAX_REPEAT 40
#define MAX_ALIASES 40
#define HISTORY_BUFFER_SIZE 10
// assuming 20 commands per tick is normal	 
#define CMDS_PER_TICK 20   	

mapping alias;

static string *history, last_input;
static int last_cmd, repeat_cnt = 0;
static int cnt = 0;

string process_input(string str)
{
	string *args, cmd, argstr;
	object me;
	int i, j;

	if (str == "")
		 return "";
	else 
		last_input = str;
	
	if (userp(this_object()) 
 	 && (this_object()->query_temp("quit/forced") || 
             !living(this_object())) )
		return "";

	if ( userp(this_object()) && living(this_object()) )
	{
	cnt++;
	me = this_object();
	if ( cnt >  3*CMDS_PER_TICK ) 
	{
		tell_object(me, "\n\n本游戏发现你滥用指令！\n\n");
		
		if ( random(2) )
		{
		message_vision(HIR"忽然一声惊雷在你头顶炸开，震得你两耳欲聋！\n"
		   "一道闪电从天降下，正劈在$N身上…\n"NOR, me);
		   
		me->set_temp("last_damage_from", "被天雷劈死了");
		me->unconcious();
		} else 
		{
		message_vision(HIR"忽然一声惊雷在你头顶炸开，震得你两耳欲聋！\n"
		   "一道闪电从天降下，直朝$N劈去……结果没打中！\n"NOR, me);
		}
		
		log_file("FLOODER", sprintf("%s(%s) was caught flooding on %s.\n",
			 me->query("name"), geteuid(me), ctime(time())));

		me->set_temp("quit/forced", 1);
		me->set_temp("quit/report_msg", "由于滥用指令被踢出游戏（Command Flooding）。");
		if ( !command("quit") ) me->delete_temp("quit");
		return "";
	} else if (cnt > CMDS_PER_TICK) 
	{
		i = (int)me->query("qi"); 
		j = 1+(cnt-CMDS_PER_TICK)/4;
		
		if (i > j) me->receive_damage("qi", j, "被天雷劈死了");
		else me->receive_damage("jing", j/2, "被天雷劈死了");
	}

	if( this_object()->query("language") == "BIG5" )
		str = "/adm/daemons/languaged"->toGB(str);

	}


	if( str[0]=='!' ) {
		if( pointerp(history) && sizeof(history) ) {
			if( sscanf(str, "!%d", i) )
				str = (string)history[(HISTORY_BUFFER_SIZE + last_cmd - i) % HISTORY_BUFFER_SIZE];
			else
				str = history[last_cmd];
		} else
			return "";
	} else {
		if( !pointerp(history) ) history = allocate(HISTORY_BUFFER_SIZE);
		last_cmd = (last_cmd + 1) % HISTORY_BUFFER_SIZE;
		history[last_cmd] = str;
	}

	if( mapp(alias) ) {

		if( !undefinedp(alias[str]) )
			return replace_string( alias[str], "$*", "" );

		if( sscanf(str, "%s %s", cmd, argstr)==2 && !undefinedp(alias[cmd]) ) {
			cmd = replace_string( alias[cmd], "$*", argstr );
			args = explode(argstr, " ");
			if( (j = sizeof(args)) )
				for(i=0; i<j; i++)
					cmd = replace_string( cmd, "$" + (i+1), args[i] );
			return cmd;
		}
	}

	return (string)ALIAS_D->process_global_alias(str);
}

void clear_cmd_count()
{
	cnt -= 2*CMDS_PER_TICK;
	if (cnt < 0) cnt = 0;
}

int query_cmd_count() { return cnt; }

int set_alias(string verb, string replace)
{
	if( !replace ) {
		if( mapp(alias) ) map_delete(alias, verb);
		return 1;
	} else {
		if( !mapp(alias) ) alias = ([ verb:replace ]);
		else if( sizeof(alias) > MAX_ALIASES )
			return notify_fail("您设定的 alias 太多了，请先删掉一些不常用的。\n");
		else alias[verb] = replace;
		return 1;
	}
}

mapping query_all_alias()
{
	return alias;
}

