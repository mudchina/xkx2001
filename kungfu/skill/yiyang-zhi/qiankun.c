//Cracked by Roath
// qiankun  一指乾坤

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

string* xuedao1 = ({
	"百会穴",
	"后顶穴",
	"强间穴",
	"脑户穴",
	"风府穴"
});

string* xuedao2 = ({
	"大锥穴",
	"陶道穴",
	"身柱穴",
	"神道穴",
	"灵台穴",
	"足三里"
});

string* xuedao3 = ({
	"中府穴",
	"尺泽穴",
	"孔最穴",
	"列缺穴",
	"太渊穴",
	"少商穴"
});

string* xuedao4 = ({
	"商阳穴",
	"合谷穴",
	"手三里",
	"曲池穴",
	"迎香穴"
});

string* xuedao5 = ({
	"百会穴",
	"灵台穴",
	"太阳穴",
	"膻中穴",
	"命门穴",
	"鸠尾穴",
	"气海穴"
});


int perform(object me, object target)
{
	int sp, dp, time;

	if (!me->is_fighting())
		return notify_fail("你必须在战斗中才能使用一指乾坤！\n");

	if (!target && me->is_fighting()) target = offensive_target(me);

	if (!target || !target->is_character() || target->query("race") != "人类")
		return notify_fail("你要点谁的穴？\n");

	if (target->is_busy())
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧ⅵ\n");

	if (me->query_str() < 28)
		return notify_fail("你在臂力上先天禀赋不足，点穴反受其害！\n");
	
	if (me->query_skill("yiyang-zhi", 1) < 100)
		return notify_fail("你在一阳指上下的功夫还不够，不会一指乾坤！\n");

	if (me->query_skill("kurong-changong", 1) < 80)
		return notify_fail("你的内功修为火候未到，无法点穴！\n");

	if (me->query_skill_mapped("force") != "kurong-changong")
		return notify_fail("你所用的内功与「一指乾坤」气路相悖！\n");

	if (me->query("neili") <= 200)
		return notify_fail("你的内力不足，，无法使一指乾坤！\n");

	if (me->query("jingli") <= 50)
		return notify_fail("你的精力不足，，无法使一指乾坤！\n");

	if (me->query("max_neili") <= 1000)
		return notify_fail("你的内力修为不足，劲力不能贯透，无法使一指乾坤！\n");

	sp = (me->query_skill("finger")*2
		+ me->query("int")*40
		+ me->query("combat_exp")/3000);

	dp = (target->query_skill("dodge")
		+ target->query_skill("parry")
		+ me->query("int")*30
		+ target->query("combat_exp")/3000);

	if (target->query("family/family_name")=="白驼山"
		&& target->query_skill_mapped("force")=="hamagong")
		dp = dp-dp/3;

	time = me->query_skill("yiyang-zhi",1)/30+random(3);
		
	if (random(sp) > dp/2 ) {
		
		if( me->query_skill("finger") >=  80 && me->query_skill("finger") < 120)
			message_vision(HIR "\n$N向前疾跨一步，左手需晃一招，右手双指直戳，点中了$n的" + xuedao1[random(5)] + "！\n\n" NOR, me, target);

		if( me->query_skill("finger") >= 120 && me->query_skill("finger") < 180)
			message_vision(HIR "\n$N龙行虎步，隐有君王之色，信手点去，一指戳在了$n的" + xuedao2[random(6)] + "！\n\n" NOR, me, target);


		if( me->query_skill("finger") >= 180) 
			message_vision(HIR "\n$N面色凝重，气贯丹田，单指缓缓戳出，一股内力破空而出，正中$n的" + xuedao4[random(5)] + "！\n\n" NOR, me, target);

		me->add("neili",-150);
		me->add("jingli",-30);
		target->start_busy(time);
		target->add("neili",- time*30);
		target->apply_condition("yyz_damage", me->query_skill("yiyang-zhi", 1)+random(me->query_skill("yiyang-zhi", 1))
			+ target->query_condition("yyz_damage"));
		target->set_temp("yyzenemy", me->query("id"));
        }
	else
	{	
		if (random(sp)>dp/3 && me->query_skill("yiyang-zhi",1)>180)
		{
			message_vision(HIW "\n$N凌空出指，一股内力击中$n的" + xuedao2[random(6)] + "，$n急忙运气与$N的内劲对抗，虽然大耗内力，但是终于没有被点中穴道。\n" NOR, me, target);
			me->add("neili",-150);
			me->add("jingli",-30);
			if (target->query("neili")>time*200)
				target->add("neili", - time*200);
			else target->set("neili",10);
			me->start_busy(1+random(3));
			target->start_busy(1+random(2));
			target->set_temp("yyzenemy", me->query("id"));
		}
		else
		{
		message_vision(HIW "\n$N一指戳去企图点$n的穴道，不料$n眼疾身快，身形一飘，躲开了$N的攻击。$N顿时空门大露 ... \n" NOR, me, target);
		me->start_busy(1+random(3));
		}
	}

	return 1;
}
