//Cracked by Roath
// drive.c 驱赶
#include <ansi.h>
inherit F_CLEAN_UP;
//inherit F_TEAM;

mapping default_dirs = ([
        "north":        "北",
        "south":        "南",
        "east":         "东",
        "west":         "西",
        "northup":      "北边",
        "southup":      "南边",
        "eastup":       "东边",
        "westup":       "西边",
        "northdown":    "北边",
        "southdown":    "南边",
        "eastdown":     "东边",
        "westdown":     "西边",
        "northeast":    "东北",
        "northwest":    "西北",
        "southeast":    "东南",
        "southwest":    "西南",
        "up":           "上",
        "down":         "下",
        "out":          "外",
        "enter":        "里",
]);

int main(object me, string arg)
{
	object env, obj, ob;
	string target_dir, dir, dest, victim;
	mapping exit;

	if (!arg) return notify_fail("你要驱赶谁？\n");

	if( sscanf(arg, "%s %s", victim, dir) != 2 ) return notify_fail("指令错误！\n");

	if ( victim == me->query("id") ) return notify_fail("何必多此一举？\n");

	ob = present(victim, environment(me));
	if (!ob) return notify_fail("这里并无此人！\n");
	if (!living(ob)) return notify_fail("这不是活物！\n");
	
//	if (!me->query_temp("curser", 1))
//		return notify_fail("你不能这么干！\n");

    if( ob->query_condition("xs_necromancy") < 0 || !ob->query_temp("block_msg/all", 1) 
		|| (me->query("id") != ob->query("xueshan/necromancy_singer")) )
//	if (!ob->query_temp("cursed", 1) || !ob->query_temp("block_msg/all", 1))
		return notify_fail("你不能驱赶此人！\n");

	if (ob->query("no_get", 1))
		return notify_fail("这个人赶不走！\n");
	if (!wizardp(me) && wizardp(ob)) return notify_fail("大胆！竟想谋害巫师！\n");			

	if (me->query_skill("necromancy", 1) < 30)
		return notify_fail("你的降伏法火候不够！\n");

	env = environment(me);
	if( !mapp(exit = env->query("exits")) || undefinedp(exit[dir]) ) 
		return notify_fail("无此方向可去！\n");

	dest = exit[dir];

//	if( !(obj = find_object(dest)) )
 //               call_other(dest, "???");
        if( !(obj = find_object(dest)) )
                return notify_fail("无法走！\n");
	if( !wizardp(ob) && obj->query("short") == "巫师休息室" )
		return notify_fail("无法走！\n");

	if( !undefinedp(default_dirs[dir]) )
                target_dir = default_dirs[dir];
        else
                target_dir = dir;

	if ( !me->query("env/invisibility") ) 
		message_vision(HIR "$N诡笑中向$n朝"+target_dir+"一指。\n" NOR, me, ob);
	message("vision", HIR "只见"+ob->name()+"失魂落魄似的向"+target_dir+"离开。\n" NOR, environment(ob), ({ob}));
	tell_object(ob,"你在迷迷糊糊中身不由主地向"+target_dir+"离开。\n");

	if( ob->move(obj) ) {
		message( "vision", HIR "只见"+ob->name()+"失魂落魄似的走了过来。\n" NOR, environment(ob), ({ob}));
		return 1;
        }

	return 0; 
}
int help (object me)
{
        write(@HELP
指令格式 : drive <生物><方向>]

这个指令让你把某人向某个方向驱赶。

HELP
);
        return 1;
}
