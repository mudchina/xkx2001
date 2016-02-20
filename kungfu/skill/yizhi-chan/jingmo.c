//Cracked by Roath
// jingmo.c 惊魔一指

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

string* xuedao1 = ({
	"肩井穴",
	"紫宫穴",
	"中庭穴",
	"关元穴",
	"天池穴"
});

string* xuedao2 = ({
	"中渎穴",
	"风市穴",
	"环跳穴",
	"渊液穴",
	"阴谷穴",
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

	if( !me->is_fighting() ) 
		return notify_fail("你必须在战斗中才能使用惊魔一指！\n");

	if( !target && me->is_fighting() ) target = offensive_target(me);

	if( !target || !target->is_character() || target->query("race") != "人类" )
		return notify_fail("你要点谁的穴？\n");

	if( environment(target)->query("no_fight") )
		return notify_fail("在这里你不能偷袭点穴！\n");

	if( me->query_str() < 30 )
		return notify_fail("你在臂力上先天禀赋不足，点穴反受其害！\n");
	
	if( me->query_skill("yizhi-chan", 1) < 90 )
		return notify_fail("你在一指禅上下的功夫还不够，不会惊魔一指！\n");

	if( me->query_skill("hunyuan-yiqi", 1) < 60 )
		return notify_fail("你的内功修为火候未到，无法点穴！\n");

	if( me->query("max_neili") <= 500 )
		return notify_fail("你的内力修为不足，劲力不能贯透，无法使惊魔一指！\n");

	sp = me->query_skill("dodge") + me->query_skill("parry") ;
	dp = target->query_skill("dodge") + target->query_skill("parry") ;
		
	time = (me->query_skill("force") - target->query_skill("force") + me->query_skill("finger"))/10;
	if (time > 10) time = 10;

	if( me->query("neili") <= time )
		return notify_fail("你的内力不够，劲力不能贯穿穴道！\n");

	if( random(sp) > dp/2 && time > 0 )
	{
		if( me->query_skill("finger") >=  90 && me->query_skill("finger") < 115)
		message_vision(HIR "\n$N五指并拢，身形闪动间，已点中了$n的" + xuedao1[random(5)] + "！\n\n" NOR, me, target);

		if( me->query_skill("finger") >= 115 && me->query_skill("finger") < 140)
		message_vision(HIR "\n$N伸出三根手指，一挥手点中了$n的" + xuedao2[random(6)] + "！\n\n" NOR, me, target);

		if( me->query_skill("finger") >= 140 && me->query_skill("finger") < 165)
		message_vision(HIR "\n$N双指如刀如戟，着着进逼，唰地一声，已戳在了$n的" + xuedao3[random(6)] + "上！\n\n" NOR, me, target);

		if( me->query_skill("finger") >= 165 && me->query_skill("finger") < 190)
		message_vision(HIR "\n$N伸出一根中指，一道青气破空而出，嗤地射中了$n的" + xuedao4[random(5)] + "！\n\n" NOR, me, target);

		if( me->query_skill("finger") >= 190 )
		message_vision(HIR "\n$N指端微伸，劲力无影无踪地发出，$n顿时全身酸麻，已被点中了" + xuedao5[random(7)] + "！\n\n" NOR, me, target);

		me->add("neili", (-50)*time);
		target->start_busy(time);
        }
	else
	{	
		message_vision(HIW "\n$N一指点去，可是$n早已料敌机先，一闪身避了开去！ \n\n$N身前顿时空门大露，狼狈地招架着 .... \n" NOR, me, target);
                // if( !target->is_killing(me) ) target->kill_ob(me);
                me->start_busy(time/5);
        }
        return 1;
}
