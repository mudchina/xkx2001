// liaodu.c

#include <ansi.h>

int exert(object me, object target)
{
        if( me->is_fighting() )
                return notify_fail("战斗中运功驱毒？找死吗？\n");

	if ((int)me->query_condition("chilian_poison") > 0) {
        if ((int)me->query_skill("wudu-xinfa", 1) < 40)
                return notify_fail("你的五毒心法修为还不够驱赤练神掌毒所需。\n");
        if( (int)me->query("neili") < 200 )
                return notify_fail("你的真气不够驱赤练神掌毒所需。\n");

        if ((int)me->query_condition("chilian_poison") > me->query_skill("wudu-xinfa",1) )
                return notify_fail("你中的赤练神掌毒过深，现在驱不掉。\n");

        write( HIW "你全身绷紧，仰面躺下来开始运功驱毒。\n" NOR);
        message_vision(
                HIW "$N大叫两声，吐出一口黑紫色的瘀血。\n" NOR,
                me);
        me->apply_condition("chilian_poison", 0);
        me->add("neili", -200);
   }
   else write("你并未中毒。\n");

        return 1;
}
