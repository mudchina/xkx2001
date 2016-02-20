//Cracked by Roath
// special drink.c
#include <dbase.h>
#include <ansi.h>

int exert(object me, object target)
{
	if (!wizardp(me))
            return notify_fail("这功能还不开放。\n");
	if (!target || !target->query("max_liquid") )
            return notify_fail("这不是装水的容器。\n");

	if (target->query("liquid/remaining") < 1 )
            return notify_fail(target->name()+"里面没什么可以喝的了。\n");

	if( me->is_fighting() )
		return notify_fail("战斗中喝什么东西？\n");

	if ((int)me->query_skill("zixia-gong", 1) < 40)
		return notify_fail("你的紫霞神功修为还不够。\n");
	if( (int)me->query("neili") < 50 ) // - (int)me->query("max_neili") < 50 )
		return notify_fail("你的真气不够。\n");

	if( me->query("water") >= me->max_water_capacity() )
		return notify_fail("你已经喝太多了，再也灌不下一滴水了。\n");


        message_vision(MAG "见$N神凝丹田，息游紫府，身若凌虚而超华岳，气如冲霄而撼北辰，将紫霞功使得出神入化，奥妙无穷。\n" NOR, me, target);
        message_vision(HIW "$N把$n"+HIW"凑到嘴上，张口便喝，只听得骨嘟骨嘟直响，竟不换气，犹似乌龙取水，把$n"+HIW"里的"+target->query("liquid/name")+"喝得滴涓不剩。\n" NOR, me, target);

	if( me->is_fighting() ) me->start_busy(2);


	me->add("water", 30 * target->query("liquid/remaining", 1));
	target->set("liquid/remaining", 0);
	if( target->query("liquid/drink_func") ) return 1;

	switch(target->query("liquid/type")) {
		case "alcohol":
			me->apply_condition("drunk",
				(int)me->query_condition("drunk") 
				+ (int)target->query("liquid/drunk_apply")
				+ (int)me->query("max_neili") / 25);
			break;
	}
	

	me->add("neili", -10*target->query("liquid/remaining", 1));
	me->start_busy(3);

	return 1;
}
