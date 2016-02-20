//Cracked by Roath
// fuxue.c 拈花拂穴

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

string* xuedao1 = ({
	"四白穴",
	"地仓穴",
	"大迎穴",
	"峡车穴",
	"头维穴",
	"下关穴"
});

string* xuedao2 = ({
	"隐白穴",
	"太白穴",
	"商丘穴",
	"地机穴"
});

string* xuedao3 = ({
	"少冲穴",
	"少海穴",
	"通理穴",
	"神门穴"
});

string* xuedao4 = ({
	"印堂穴",
	"金律穴",
	"玉液穴",
	"鱼腰穴",
	"百劳穴"
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

	if( !target && me->is_fighting() ) target = offensive_target(me);

	if ( me->query_temp("weapon") ) 
		return notify_fail("拿着武器怎么点穴？\n");

	if( !target || !target->is_character() || target->query("race") != "人类" )
		return notify_fail("你要点谁的穴？\n");

	if( environment(target)->query("no_fight") )
		return notify_fail("在这里你不能偷袭点穴！\n");

	if( me->query_str() < 25 )
		return notify_fail("你在臂力上先天禀赋不足，点穴反受其害！\n");
	
	if( me->query_skill("finger") < 90 )
		return notify_fail("你在指法上下的功夫还不够，不会拈花拂穴！\n");

	if( me->query_skill("hunyuan-yiqi", 1) < 90 )
		return notify_fail("你的内功修为火候未到，无法使用拈花拂穴！\n");

	if( me->query("max_neili") <= 300 )
		return notify_fail("你的内力修为不足，劲力不能贯透，无法点穴！\n");

	sp = me->query_skill("dodge") + me->query_skill("parry") + me->query("kar");
	dp = target->query_skill("dodge") + target->query_skill("parry") + target->query("kar");
		
	time = (me->query_skill("force") - target->query_skill("force") + me->query_skill("nianhua-zhi",1))/15;

	if( me->query("neili") <= 2*time )
		return notify_fail("你的内力不够，劲力不能贯穿穴道！\n");

	if( random(sp) > dp && time > 0 )
	{
		if( me->query_skill("finger") >=  90 && me->query_skill("finger") < 115)
		message_vision(HIR "\n$N五指并拢，身形闪动间，已点中了$n的" + xuedao1[random(6)] + "！\n\n" NOR, me, target);

		if( me->query_skill("finger") >= 115 && me->query_skill("finger") < 140)
		message_vision(HIR "\n$N伸出三根手指，一挥手点中了$n的" + xuedao2[random(4)] + "！\n\n" NOR, me, target);

		if( me->query_skill("finger") >= 140 && me->query_skill("finger") < 165)
		message_vision(HIR "\n$N双指如刀如戟，着着进逼，唰地一声，已戳在了$n的" + xuedao3[random(4)] + "上！\n\n" NOR, me, target);

		if( me->query_skill("finger") >= 165 && me->query_skill("finger") < 190)
		message_vision(HIR "\n$N交叉两根食指，一缕罡气破空迸出，笔直射入$n的" + xuedao4[random(5)] + "！\n\n" NOR, me, target);

		if( me->query_skill("finger") >= 190 )
		message_vision(HIR "\n$N食指轻弹，一片排山倒海的暗劲顿时涌出，击在$n的" + xuedao5[random(7)] + "上！\n\n" NOR, me, target);

		me->add("neili", (-10)*time);
		if( me->query_temp("jingang") )me->add("neili", (-20)*time); // jingang can make own bili 4 times, too rascal,
																						 // so jingang+fuxue combo should consume more neili
		target->start_busy(time);

		}
	else
	{	
		message_vision(HIW "\n$N一指点去，可是$n早已料敌机先，一闪身避了开去！ \n\n$N身前顿时空门大露，狼狈地招架着 .... \n" NOR, me, target);
		if( !target->is_fighting(me) ) target->fight_ob(me);
		me->start_busy(5);
	}
        if (random(2) == 1) {
	    if (! target->is_killing(me)) target->kill_ob(me);
 	}

	return 1;
}
