//Cracked by Roath
// jinding-zhang.c 金顶绵掌

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : "$N向$n遥遥一鞠，一式「三阳开泰」，双掌大开大阖，挡开$n的进击",
        "force" : 160,
        "dodge" : 15,
        "parry" : 20,
        "damage": 20,
        "lvl" : 0,
        "skill_name" : "三阳开泰",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N面含微笑，一式「五气呈祥」，双掌云缠雾绕，同时攻向$n全身各处",
        "force" : 200,
        "dodge" : 15,
        "parry" : 20,
        "damage": 20,
        "lvl" : 10,
        "skill_name" : "五气呈祥",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N使一式「罡风推云」，双手化掌，一前一后向前猛推，击向$n的$l",
        "force" : 260,
        "dodge" : 20,
        "parry" : 25,
        "damage": 15,
        "lvl" : 20,
        "skill_name" : "罡风推云",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N划身错步，一式「逆流捧沙」，双掌内拢外托，攻向$n的下盘",
        "force" : 320,
        "dodge" : 20,
        "parry" : 25,
        "damage": 25,
        "lvl" : 40,
        "skill_name" : "逆流捧沙",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N一式「雷洞霹雳」，双掌以迅雷不及掩耳之势，劈向$n的两额太阳穴",
        "force" : 400,
        "dodge" : 20,
        "parry" : 25,
        "damage": 35,
        "lvl" : 60,
        "weapon" : "掌风",
        "skill_name" : "雷洞霹雳",
        "damage_type" : "割伤"
]),
([      "action" : "$N怒叱一声，一式「金顶佛光」，闪步上引，挥掌疾拍$n的顶心死穴",
        "force" : 450,
        "dodge" : 20,
        "parry" : 25,
        "damage": 40,
        "lvl" : 70,
        "skill_name" : "金顶佛光",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N一式「梵心降魔」，双掌似让非让，似顶非顶，气浪如急流般使$n陷身其中",
        "force" : 500,
        "dodge" : 15,
        "parry" : 20,
        "damage": 45,
        "lvl" : 80,
        "skill_name" : "梵心降魔",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N意沉，势沉，心沉，气沉，一式「法尊八荒」，罡风铺天盖地般地向$n涌去",
        "force" : 550,
        "dodge" : 30,
        "parry" : 20,
        "damage": 50,
        "lvl" : 100,
        "skill_name" : "法尊八荒",
        "damage_type" : "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_combine(string combo) { return combo=="tiangang-zhi"; }

int valid_learn(object me)
{
        if (me->query_str() < 25 && me->query("str") < 20 )
                return notify_fail("你的臂力不足，无法学练金顶绵掌。\n");
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练金顶绵掌必须空手。\n");
        if ((int)me->query_skill("linji-zhuang", 1) < 20)
                return notify_fail("你的临济十二庄火候不够，无法学金顶绵掌。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练金顶绵掌。\n");
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
        int i, jiali;
        int level   = (int) me->query_skill("jinding-zhang",1);
        mapping px_info;
	object victim, ob;

	// lasting effects of piaoxue
        ob = me->select_opponent();

        px_info = me->query_temp("piaoxue/usage_info");
        victim = me->query_temp("piaoxue/target");

        if ( objectp(victim) && ob == victim ) {
	    jiali=me->query("jiali");
	    if (jiali > px_info["neili_damage"]) 
		jiali = px_info["neili_damage"];
	    if (ob->query("neili") > 0) {
		message_vision(HIY "\n$n摸不透$P的内力虚实，只好大耗真力，把全身都布满真气。\n" NOR, me, victim);
		ob->add("neili", -jiali);
	    } else {
		message_vision(HIY "\n$n一口真气提不上来，被$P掌风扫中，脚下踉跄，差点儿倒下。\n" NOR, me, victim);
		ob->receive_damage("qi", jiali, me);
	    }
        }

        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("jingli") < 30)
                return notify_fail("你的精力太低了。\n");
        if ((int)me->query("neili") < 10)
                return notify_fail("你的内力不够练金顶绵掌。\n");
        me->receive_damage("jingli", 30);
        me->add("neili", -10);
        return 1;
}


string perform_action_file(string action)
{
        return __DIR__"jinding-zhang/" + action;
}

