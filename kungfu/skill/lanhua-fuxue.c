//Cracked by Roath

//lanhuafuxue-shou.c
//kane 05/9/97  

#include <combat.h>
#include <ansi.h>

inherit SKILL;
inherit F_DBASE;
inherit F_SSERVER;

string* xuedao = ({
        "巨骨穴",
        "地仓穴",
        "肩井穴",
        "颊车穴",
        "承泣穴",
        "风池穴",
        "章门穴",
        "风府穴",
        "精促穴",
        "陶道穴",
        "强间穴",
        "少海穴",
        "犊鼻穴",
        "神门穴",
        "华盖穴",
        "大椎穴",
        "太阳穴",
        "膻中穴",
        "命门穴",
        "鸠尾穴",
        "三阴交",
        "天柱穴"
});

mapping *action = ({
([      "action" :"$N左掌在身前一划，使出一招「花疏云淡」，右手挥出，食指与拇指扣起，余下三指略张，手掌如兰花般伸出，拂向$n“曲池穴”",
        "force" : 130,
        "dodge" : 10, 
        "parry" : 5, 
        "damage": 10,
        "lvl" : 0,
        "skill_name" : "花疏云淡",
        "damage_type" : "内伤"
]),
([      "action" :"$N身形旋转，一式「轻云蔽月」，右掌虚拍$n的$l，左手作兰花之形，小指、无名指轻描淡写地拂向$n睛明、承泣二穴",
        "force" : 180,
        "dodge" : 15, 
        "parry" : 5, 
        "damage": 20,
        "lvl" : 10,
        "skill_name" : "轻云蔽月",
        "damage_type" : "内伤"
]),
([      "action" :"$N使出一招「云破月来」，左手挥出，三指微张，罩住$n上身三处大穴，忽然间右手如蜻蜓点水般伸出，疾拂$n左右太阳穴",
        "force" : 220,
        "dodge" : 25, 
        "parry" : 5, 
        "damage": 25,
        "lvl" : 15,
        "skill_name" : "云破月来",
        "damage_type" : "内伤"
]),
([      "action" :"$N倒踩七星步，如穿花蝴蝶般绕到$n身后，靠背而立，使出一招「幽兰弄影」，反手拂向$n大椎、至阳二穴，出手若有若无，端的奥妙无方",
        "force" : 280,
        "dodge" : 30, 
        "parry" : 5, 
        "damage": 25,
        "lvl" : 30,
        "skill_name" : "幽兰弄影",
        "damage_type" : "内伤"
]),
([      "action" :"$N前趋一步，双手齐出，一招「芳兰竟体」，左右手小指拂向$n腋底极泉穴，中指点向肩井穴，拇指扣向紫宫穴，刹那间连袭$n六处大穴",
        "force" : 350,
        "dodge" : 30, 
        "parry" : 10, 
        "damage": 35,
        "lvl" : 40,
        "skill_name" : "芳兰竟体",
        "damage_type" : "内伤"
]),
([      "action" :"$N身形展动，蓦地移到$n侧面，使出一式「兰桂齐芳」，双手颤动，右手行云流水般拂向$n任脉诸穴，左手则影影绰绰罩住$n督脉诸穴",
        "force" : 380,
        "dodge" : 40, 
        "parry" : 10, 
        "damage": 50,
        "lvl" : 50,
        "skill_name" : "兰桂齐芳",
        "damage_type" : "内伤"
]),
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }
/*
int valid_combine(string combo)
{
        object me = this_player();
        if( me->query("gender") == "女性" )
                return combo=="luoying-shenjian";
}
*/
int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练兰花拂穴手必须空手。\n");
        if ((int)me->query_skill("bitao-xuangong", 1) < 20)
           return notify_fail("你的碧涛玄功火候不够，无法学兰花拂穴手。\n");
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{
        int i, level, bt, dp;
	object victim;
	string xue, *msg;

	if( !victim && me->is_fighting() ) victim = offensive_target(me);
        level  = (int) me->query_skill("lanhua-fuxue",1);
        bt  = (int) me->query_skill("bitao-xuangong",1);
	dp = (int) victim->query_skill("dodge",1);
	xue = xuedao[random(sizeof(xuedao))];


	if(me->query_temp("luoying_lanhua"))
	{
	me->prepare_skill("hand");
	me->prepare_skill("strike", "luoying-shenjian");
	COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
	me->prepare_skill("strike");
	me->prepare_skill("hand", "lanhua-fuxue");
	}

	msg = 
	({
		HIG"$N左手轻挥，往$n掌背“阳池穴”上拂去，这一拂轻灵飘逸，认穴奇准，实是非同小可！"NOR,
		HIC"突然间$N左手斜挥，轻轻拂向$n左颈“天鼎”“巨骨”两穴，灵巧轻柔，右手运劲若有若无，拂向$n右手手肘“小海穴”！"NOR,
		HIW"忽见$N一只雪白的手掌五指分开，形如兰花，姿态曼妙难言，出手优雅，气度闲逸地拂向$n的"+xue+"！"NOR,
		HIC"$N手腕小指轻拂而出，这一式出招快捷，认穴极准，却又如轻描淡写，行若无事"NOR,
	});

	if( me->query_temp("fuxue") && random(4) == 0 )
	{
		victim->delete_temp("xue");
		victim->set_temp("xue",xue);

		return ([
		"action": msg[random(sizeof(msg))],
		"force" : 400+random(40),
		"dodge" : 20,
		"damage": 50+random(20),
		"damage_type" : "内伤" ]);
	}

	else if ( !me->query_temp("luoying_lanhua") 
	&& level > random(level+400) && me->query("neili") > 300 
	&& me->query("combat_exp") > random(victim->query("combat_exp")*2) 
	&& !victim->is_busy() ) {
                me->add("neili", -20);
                message_vision(HIC"\n$N淡然一笑，出手若春兰葳蕤，晓风过林，似慢实快，若重还轻拂向$n的"+xue+"，已深得快、准、奇、清四字要诀！\n"NOR,me,victim);
        	message_vision(GRN"$N微一疏神，被拂个正着，只觉得"+xue+"上一阵酸麻，行动不免迟缓下来。\n"NOR,victim);
		victim->start_busy(1 + random(level/50));
	}

        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}


int practice_skill(object me)
{
        if ((int)me->query("jingli") < 50)
                return notify_fail("你的精力太低了。\n");
	if ((int)me->query("neili") < 50)
                return notify_fail("你的内力太低了。\n");
        me->receive_damage("jingli", 15);
	me->add("neili", -5);
       
       return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int level, jiali;
        level = (int) me->query_skill("lanhua-fuxue",1);
	jiali = me->query("jiali");
        if( me->query_temp("fuxue")  ) {
	victim->start_busy(level/100 +random(jiali/100+1));
	victim->add("neili", -(30 + jiali/2));
        me->interrupt_me();
	return "$n微一疏神，被拂个正着，只觉得"+victim->query_temp("xue")+"上一阵酸麻，行动不免迟缓下来。\n";
        }
}

string perform_action_file(string action)
{
	return __DIR__"lanhua-fuxue/" + action;
}
