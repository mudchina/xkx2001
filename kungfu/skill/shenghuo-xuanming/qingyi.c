//Cracked by Roath
// qingyi.c 青翼九天

#include <ansi.h>

int exert(object me, object target)
{
	int dex, dex2, amount;

        if( !me->is_fighting() )
                return notify_fail("青翼九天只能在战斗中使用。\n");

	if (me->query_temp("qingyi"))
		return notify_fail("你已经在使用青翼九天了。\n");

	if (((int)me->query_encumbrance()*100/(int)me->query_max_encumbrance()) > 50)
		return notify_fail("你负重太多，怎么也使不出青翼九天。\n");

        if( me->query_dex() < 30 )
                return notify_fail("你的身法不足以施展青翼九天！\n");

        if( me->query_skill_mapped("force") != "shenghuo-xuanming" )
                return notify_fail("你所用的并非圣火玄功，无法使出青翼九天！\n");

	if (me->query_skill_mapped("dodge") != "qingfu-shenfa")
		return notify_fail("你所用的并非青蝠身法，无法使出青翼九天！\n");

        if( me->query_skill("force") < 135 )
                return notify_fail("你的圣火玄功火候未到，无法施展青翼九天！\n");

        if( me->query_skill("dodge") < 135 )
                return notify_fail("你青蝠身法修为不足，还不会使用青翼九天！\n");

        if( me->query("neili") < 1000 )
                return notify_fail("你的内力不够使用青翼九天！\n");

        message_vision(HIW"$N暗提了一口内息,身子觉得轻盈了许多，紧接着$N纵声长啸，身形惊雷闪电一般，满场飞奔，渐渐化为一团白影。\n" NOR, me);

	dex = me->query("dex");		// original dex
	dex2 = me->query_dex();		// temp dex

	dex2 = dex2 * (dex/10);		// this makes original dex important, players need to reconsider 
					// their gift selection

	me->add_temp("apply/dexerity", dex2);
	me->add_temp("apply/strength", -(dex2/15) );	// reduce some bili to compensate dex increase.
	me->add("neili", -(dex2*4) );
	me->set_temp("qingyi",1);

        amount = me->query_skill("qingfu-shenfa") /5;

	call_out("remove_effect",amount,me,dex2);
        me->start_busy(1+random(2));

        return 1;
}

int remove_effect(object me, int dex2)
{
	message_vision(HIW"$N微微吐了口气，放慢身法，身形又复清晰。\n"NOR,me);
	me->add_temp("apply/dexerity", -dex2);
	me->add_temp("apply/strength", dex2/15);
	me->delete_temp("qingyi");

	return 1;
}