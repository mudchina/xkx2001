//Cracked by Roath
// cure.c
// RYU

#include <ansi.h>

int exert(object me, object target)
{
	if( me->is_fighting() )
		return notify_fail("战斗中运功疗精？找死吗？\n");

	if ((int)me->query_skill("kurong-changong", 1) < 20)
		return notify_fail("你的枯荣禅功修为还不够。\n");
	if( (int)me->query("jingli") < 50 )
		return notify_fail("你的精力不够。\n");
	if( (int)me->query("jingli") < 300 )
                return notify_fail("你的精力不够。\n");

	if( (int)me->query("eff_jing") >= (int)me->query("max_jing"))
		return notify_fail("你现在不须要疗精！\n");

	write( HIW "你在身上划一道伤口，挤出一些淤血，气沉丹田，开始凝神疗精。\n" NOR);
	message("vision",
		HIW + me->name() + "在身上划一道伤口，挤出一些淤血，脸色看起来好多了。\n" NOR,
		environment(me), me);

	me->receive_curing("jing", (int)me->query_skill("force")/2 );
	me->receive_wound("qi", 5);
	me->set("jiali", 0);

	return 1;
}
