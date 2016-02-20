//Cracked by Roath
// forcekill.c 
inherit F_CLEAN_UP;
#include <ansi.h>
int main(object me, string arg)
{
	object target, victim, dummy;
	string name1, name2;

	if (!arg) return notify_fail("你要命令谁杀谁？\n");

        if( sscanf(arg, "%s with %s", name2, name1) != 2 ) return notify_fail("指令错误！\n");

	if ( name1 == name2 ) return notify_fail("想要别人自己杀自己？你发什么神经啊？\n");
	if ( name1 == me->query("id") ) return notify_fail("何必多此一举？\n");
	if ( name2 == me->query("id") ) return notify_fail("你疯啦？要寻死也不必如此麻烦！\n");

	target = present(name1, environment(me));
        if (!target) return notify_fail("这里并无此目标！\n");
	if (!living(target)) return notify_fail("此目标不是活物！\n");
	if ( userp(target)) return notify_fail("很显然，此人不听从你的这项命令！\n");

	victim = present(name2, environment(me));
        if (!victim) return notify_fail("这里并无你想杀的目标！\n");
	if (!living(victim)) return notify_fail("你想杀的目标不是活物！\n");

	if (!wizardp(me) && (wizardp(target) || wizardp(victim))) return notify_fail("大胆！竟想谋害巫师！\n");

    if( target->query_condition("xs_necromancy") < 0 || !target->query_temp("block_msg/all", 1) 
                || (me->query("id") != target->query("xueshan/necromancy_singer")) )
//	if (!target->query_temp("cursed", 1) || !target->query_temp("block_msg/all", 1))
		return notify_fail("你不能这么干！\n");

	if (me->query_skill("necromancy", 1) < 90)
		return notify_fail("你的降伏法火候不够！\n");

	if ( !me->query("env/invisibility") )   
		message_vision(HIR "$N诡笑中对着$n念了几句密咒，又伸手指了指"+victim->name()+"。\n", me, target);
	message("vision", HIR "只见"+target->name()+"失魂落魄似的向"+victim->name()+"发动猛烈的攻击，欲制其于死地！\n" NOR, environment(target), ({target}));
	tell_object(target,"你在迷迷糊糊中身不由主地向"+victim->name()+"发动猛烈的攻击，欲制其于死地！\n");

	target->kill_ob(victim);

	return 1;
}
