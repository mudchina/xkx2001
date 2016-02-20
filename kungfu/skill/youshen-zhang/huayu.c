//Cracked by Roath
// huayu.c 漫天花雨

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	int i, num; 

	if( !target && me->is_fighting() ) target = offensive_target(me);

	if( !target
	||      !target->is_character()
	||      !me->is_fighting(target) )
		return notify_fail("漫天花雨只能对战斗中的对手使用。\n");

	if ( !objectp(weapon = present("jinshe zhui", me))  )
		return notify_fail("你身上没有金蛇锥，如何施展「漫天花雨」！\n");

	if( me->query_skill("strike") < 120 )
		return notify_fail("你在金蛇游身掌修为还不够，不能分神施展「漫天花雨」！\n");	

	if( me->query_skill("jinshe-zhuifa", 1) < 100 )
		return notify_fail("你在金蛇锥法修为还不够，不会施展「漫天花雨」！\n");

	if( me->query_skill("force") < 100 )
		return notify_fail("你的内功修为火候未到，劲力不足以施展「漫天花雨」！\n");

	if( me->query("max_neili") <= 600 )
		return notify_fail("你的内力修为不足，劲力不足以施展「漫天花雨」！\n");

	if( me->query("neili") <= 500 )
		return notify_fail("你的内力不够，劲力不足以施展「漫天花雨」！\n");

	if( weapon->query_amount() < 7 ) 
		return notify_fail("你所剩余的暗器数目不够施展「漫天花雨」！\n");

	num = 4 + random(4);
	me->add("neili", -200);
	me->add("jingli", -50);

	message_vision(HIR "\n\n$N身形滑动，退出丈许，突然施展「漫天花雨」，数枚"+weapon->name()+"或直袭、或\n"
		       "斜射、或上旋、或下击、左右包叉、前后尽罗，奔雷般地射向$n！\n" NOR, me, target);

	for (i=1; i<num+1; i++) {
		weapon->throw_ob(me, target);
                me->reset_action();
	}

	me->start_busy(1+random(3));

	return 1;
}
