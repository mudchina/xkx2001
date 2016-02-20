//Cracked by Roath
// xueshan-jian.c 凌霄城、雪山剑法 
// maco 

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : "$N横剑挥扫，这招「苍松迎客」出剑极是沉着，朴实无华，偶然间锋芒一现，又即收敛，却是守中含攻，凝重狠辣",
        "force" : 100,
        "dodge" : 10,
        "damage": 20,
        "lvl" : 0,
        "skill_name" : "苍松迎客",
        "damage_type" : "劈伤"
]),
([      "action" : "$N手中$w颤成了一团剑花，剑尖刺向$n$l，轻灵翔动，迅捷无伦，这一招「岭上双梅」虽是一招，却是两刺，一剑刺出后跟着又刺一剑",
        "force" : 120,
        "dodge" : -10,
        "parry" : 15,
        "damage": 30,
        "lvl" : 5,
        "skill_name" : "岭上双梅",
        "damage_type" : "刺伤"
]),
([      "action" : "$n连取了数招守势，使得是一招「老枝横斜」，深自收敛，剑招走上了绵密稳健的路子，剑尖倏地一翻，斜刺$n$l，招式古朴，却自有一股凌厉的狠劲，",
        "force" : 140,
        "dodge" : 10,
        "parry" : -5,
        "damage": 25,
        "lvl" : 10,
        "skill_name" : "老枝横斜",
        "damage_type" : "刺伤"
]),
([      "action" : "$N左指暗含伸指点穴的後着，右肘微抬，摆出「云横西岭」架式，剑光密集之中，$w犹似电闪般递出，中宫直进，剑尖已指住了$n$l",
        "force" : 170,
        "dodge" : 5,
        "parry" : -10,
        "damage": 35,
        "lvl" : 10,
        "skill_name" : "云横西岭",
        "damage_type" : "刺伤"
]),
([      "action" : "$N一剑疾刺，二剑继出，使的正是一招「双驼西来」，塞外大漠飞沙、驼马奔驰的意态，尽在$w剑势之中隐然而现",
        "force" : 190,
        "dodge" : -10,
        "parry" : -5,
        "damage": 40,
        "lvl" : 15,
        "skill_name" : "双驼西来",
        "damage_type" : "刺伤"
]),
([      "action" : "$N$w挺起，使一招「飞沙走石」，势挟劲风，内劲直贯剑尖，寒光点点，直向$n$l刺去，出手迅猛，剑招纵横",
        "force" : 210,
        "dodge" : 20,
        "parry" : -5,
        "damage": 45,
        "lvl" : 20,
        "skill_name" : "飞沙走石",
        "damage_type" : "刺伤"
]),
([      "action" : "$N$w微颤，斜指$n，这一招「月色昏黄」使得若有若无，朦朦胧胧，深得雪山剑法的神髓，精奇无比",
        "force" : 230,
        "dodge" : 0,
        "parry" : 45,
        "damage": 55,
        "lvl" : 20,
        "skill_name" : "月色昏黄",
	"damage_type": random(2)?"刺伤":"劈伤"
]),
([      "action" : "$N剑起中锋，嗤的一声，向$n$l直刺过去，这招「胡马越岭」轻灵自然，矫捷狠辣，剑势来得凌厉之极",
        "force" : 250,
        "dodge" : 10,
        "parry" : 0,
        "damage": 45,
        "lvl" : 25,
        "skill_name" : "胡马越岭",
        "damage_type" : "刺伤"
]),
([      "action" : "$N劲贯剑身，全力进击，将这招「风沙莽莽」精微之处使得淋漓尽致，剑势似有狂风黄沙之重压，$w使开来矫矢灵动，招招狠辣",
        "force" : 280,
        "dodge" : 0,
        "parry" : 10,
        "damage": 50,
        "lvl" : 30,
        "skill_name" : "风沙莽莽",
	"damage_type": random(2)?"刺伤":"劈伤"
]),
([      "action" : "$N剑法转招「朔风忽起」，$w犹如雪花飞舞之姿，朔风呼号之势，出招迅捷，一招刺出，陡然间剑气大盛，去势并不甚急，但内力到处，却激得风声嗤嗤而呼",
        "force" : 300,
        "dodge" : -5,
        "parry" : 5,
        "damage": 50,
        "lvl" : 35,
        "skill_name" : "朔风忽起",
        "damage_type" : "刺伤"
]),
([      "action" : "$N陡地向後滑出一步，一招「明月羌笛」，剑光闪烁中，$N一声长啸，刷刷刷连展三剑，第四剑青光闪处，$w直掠$n的$l",
        "force" : 320,
        "dodge" : 0,
        "parry" : 5,
        "damage": 55,
        "lvl" : 40,
        "skill_name" : "明月羌笛",
        "damage_type" : "劈伤"
]),
([      "action" : "$N抢上三步，挺剑刺出，带转剑锋，斜削$n$l，这一招「雪泥鸿爪」出剑部位极巧，发挥了雪山派剑法的绝艺",
        "force" : 350,
        "dodge" : 0,
        "parry" : 5,
        "damage": 65,
        "lvl" : 45,
        "skill_name" : "雪泥鸿爪",
        "damage_type" : "劈伤"
]),
([      "action" : "但见$N$w生出点点剑光，一招「梅雪争春」，虚中有实，实中有虚，剑尖剑锋齐用，剑尖是雪点，剑锋乃梅枝，四面八方向$n攻了过来，寒光耀眼，似有万点雪花倾将下来",
        "force" : 380,
        "dodge" : 10,
        "parry" : -10,
        "damage": 75,
        "lvl" : 50,
        "skill_name" : "梅雪争春",
	"damage_type": random(2)?"刺伤":"劈伤"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("sword",1) < 30)
                return notify_fail("你的基本剑法火候太浅。\n");
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
        int i, level;
        object target;

        level   = (int) me->query_skill("xueshan-jian",1);
        target = me->select_opponent();
        weapon = me->query_temp("weapon");

	if( me->query_temp("xuehua") )
	{
		return ([
		"action": HIC"$N手腕轻抖，一刹那中朝$n连刺六剑，每一剑都凭手腕颤动，幻成"+HIW"「雪花六出」"+HIC"，手法之快，实是无与伦比，出剑还剑，只一瞬间之事"NOR,
		"force" : 450+random(60),
		"dodge" : 30,
		"damage": 60+random(60),
	        "skill_name" : "雪花六出",
		"damage_type" : "刺伤" ]);
	}
	if( random(4)==1 && random(level) > 150)
	{
		return ([
		"action" : HIY"$N手中$w"+HIY"微微颤动，剑光若有若无，这招"+HIW"「暗香疏影」"NOR+HIY"是雪山剑法中最精微的一招，宛若梅树在风中摇曳不定，剑法中夹杂了梅花、梅萼、梅枝、梅干的形态，古朴飘逸，兼而有之"NOR,
        	"force" : 400,
        	"dodge" : -10,
        	"parry" : -20,
        	"damage": 120,
        	"lvl" : 60,
        	"skill_name" : "暗香疏影",
		"damage_type": random(2)?"刺伤":"劈伤"]);
	}

        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("jingli") < 50)
                return notify_fail("你的精力不够练雪山剑法。\n");
        me->receive_damage("jingli", 30);
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{
	int level, jiali, time;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("xueshan-jian",1);
	jiali = me->query("jiali");
        if( me->query_temp("xuehua")  ) {
	victim->receive_wound("qi", random(jiali));
	return HIR"只见$n$l上鲜血渗出，六点剑痕布成六角，已被"+weapon->name()+HIR"整整齐齐的刺了六点。\n"NOR;
        }
}

string perform_action_file(string action)
{
        return __DIR__"xueshan-jian/" + action;
}
