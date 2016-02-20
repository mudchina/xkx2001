//Cracked by Kafei
// edit.c

#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string file)
{
	if( !file ) return notify_fail("指令格式：edit <档名>\n");
/*
	if( me->query("id") != "server" 
		&& me->query("id") != "xuanyuan"
		&& me->query("id") != "lbc"
		&& me->query("id") != "liu"
		&& me->query("id") != "linglong"
		&& me->query("id") != "lax") 
	return notify_fail("你没有修改这个档案的权利\n");
*/
	if( in_edit(me) ) return notify_fail("你已经在使用编辑器了。\n");

	seteuid(geteuid(me));
	ed(resolve_path(me->query("cwd"), file));
        log_file("static/editfile", sprintf("%s%s edit %s (%s)\n",
                me->query("name"),
                "(" + me->query("id") + ")" ,
                resolve_path(me->query("cwd"), file),
                ctime(time())
                ) );
	return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : edit <档名>, edit here

利用此一指令可直接在线上编辑档案。
HELP
    );
    return 1;
}
