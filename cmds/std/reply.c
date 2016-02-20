//Cracked by Roath
// reply.c

#include <ansi.h>
#include <net/dns.h>

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string target, mud;
	object obj;

	if( !arg || arg=="" )
		return notify_fail("你要回答什么？\n");

	if( !stringp(target = me->query_temp("reply")) )
		return notify_fail("刚才没有人和你说过话。\n");

	if( sscanf(target, "%s@%s", target, mud)==2 ) {
		GTELL->send_gtell(lower_case(mud), lower_case(target), me, arg);
		write("网路讯息已送出，可能要稍候才能得到回应。\n");
		return 1;
	}

	obj = find_player(target);
	if( !obj )
		return notify_fail("刚才和你说话的人现在无法听见你，或者已经离开游戏了。\n");
	if (!wizardp(me) && wizardp(obj) && obj->query("env/block")=="YES")
                return notify_fail(obj->name()+"很忙，有什么事待会儿再说吧。\n");
        if (!wizardp(me) && obj->query("env/block") == (string)me->query("id"))
                return notify_fail(obj->name()+"不想听你罗唆。\n");

	write(GRN "你回答" + obj->name(1) + "：" + arg + "\n" NOR);
	tell_object(obj, sprintf(GRN"%s(%s)回答你：%s\n"NOR,
		me->name(1), me->query("id"), arg ));

	obj->set_temp("reply", me->query("id"));
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式：reply <讯息>

你可以用这个指令和刚才用 tell 和你说话的使用者说话。

see also : tell
HELP
	);
	return 1;
}
