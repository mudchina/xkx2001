//Cracked by Roath
// blood.c 噬血
// zhangchi 8/00

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string weapon;

        if( !target ) target = offensive_target(me);

        if( !target || !living(target))
                return notify_fail("你要吸谁的血？\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("此技只能空手运用。\n");

        if( environment(target)->query("no_fight") )
                return notify_fail("在这里你不能偷袭！\n");

        if( me->query_dex() < 30 )
                return notify_fail("你的身法不足以施展此技！\n");

        if( me->query_skill_mapped("force") != "shenghuo-xuanming" )
                return notify_fail("你所用的并非圣火玄冥功，无法施展此技！\n");

        if( me->query_skill_mapped("dodge") != "qingfu-shenfa" )
                return notify_fail("你并未具备青蝠身法，如何施展此技？\n");

        if( me->query_skill("force") < 135 )
                return notify_fail("你的内功火候未到，无法施展此技！\n");

        if( me->query_skill("qingfu-shenfa") < 100 )
                return notify_fail("你青蝠身法修为不足，还不会使用此技！\n");

        if( me->query("neili") < 1000)
                return notify_fail("你的内力不够！\n");

        message_vision(HIB "$N脸色变得煞白，突然欺到$n身边，张嘴就朝$n颈侧咬去！！\n\n" NOR, me, target);

	target->kill_ob(me);	

	if ( me->query_dex() > random(target->query_dex()*2)
	&&   me->query("neili") > random(target->query("neili")*2)
	&&   me->query("jingli") > random(target->query("jingli")*2) )
	{	// 50% * 50% * 50% = 12.5% chance between 2 identical players.
		message_vision(HIR"结果一下子咬在$n的颈侧，猛吸起来，一股鲜血登时从$N的牙边渗出，阴森可怖。\n\n"NOR,me,target);
		
		if ( me->query("combat_exp") > random(target->query("combat_exp")*10) )		// low chance
		{
message_vision(HIR"只见$N的腹部微微鼓起，然后放开$n。再看时，$n已经血被吸干，早已气绝。\n"NOR,me,target);
			me->receive_curing("qi",target->query("max_qi")+100);
			me->add("qi",target->query("max_qi")+100);
			target->set("qi", -1);
			target->receive_wound("qi", target->query("max_qi")+100, "血被吸干而死" );
		}
		else
		{
			message_vision(HIW"$n拼死挣扎，终于挣脱$N的控制，但受伤极重，鲜血从颈部汩汩流出。\n"NOR,me,target);
			me->receive_curing("qi",target->query("max_qi")/3);
			me->add("qi",target->query("max_qi")/3);
			target->set("qi", 1000);
			target->receive_wound("qi", target->query("max_qi")/3, "血被吸干而死" );
		}
		me->set_temp("blood_sucked",1);
		if (me->query("id") == "wei yixiao")
			me->apply_condition("wei_pk",100);
	}
	else	
	{
		message_vision(HIW"$n大惊之下，急忙闪身躲开。$N一击不中，体内寒毒攻心，登时打了几个哆嗦，内受重伤。\n"NOR,me,target);
		me->add("qi", me->query("max_qi")/10);
		me->receive_wound("qi", me->query("max_qi")/10, "寒毒攻心死了");
	}

	me->add("neili", -200);
	me->add("jingli", -100);

        me->start_busy(2+random(3));

        return 1;
}
