//Change by Server (5/25/2001)
// semote.c

#include "/doc/help.h"

inherit F_CLEAN_UP;

int lead_match(string str, string arg)
{
	if (stringp(str) && stringp(arg))
		return str[0] == arg[0];
	return 0;
}

int main(object me, string arg)
{
	string *e;
	string msg;
	int i;

	e = sort_array(EMOTE_D->query_all_emote(), 1);
	if (arg)
		e = filter_array(e, (: lead_match :), arg);
	msg = "◎ 侠客行 ◎ 有下列系统预设的动作：\n";
	for(i=0; i<sizeof(e); i++)
		msg = sprintf("%s%-15s%s", msg, e[i], (i%5==4)?"\n": "");
	msg += "\n";
	me -> start_more(msg);
	return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : semote 
	   semote [a-z]

这个指令可以列出目前所能使用的emote.
HELP
    );
    return 1;
}
