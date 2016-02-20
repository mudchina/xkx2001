//Cracked by Roath
// tiangang-zhi.c 天罡指穴法

inherit SKILL;

mapping *action = ({
([      "action" : "$N一式「浪起湖心」，肩脊发力，于无形无象之中，指尖如鱼跃水，点向$n的$l",
        "force" : 200,
        "dodge" : 15,
        "lvl" : 0,
        "weapon": "指力",
        "skill_name" : "浪起湖心",
        "damage_type" : "刺伤"
]),
([      "action" : "$N右掌斜举，一式「瀑落清潭」，左指沿右臂滚动，指向$n的中三路要害",
        "force" : 300,
        "dodge" : 15,
        "lvl" : 10,
        "weapon": "指力",
        "skill_name" : "瀑落清潭",
        "damage_type" : "刺伤"
]),
([      "action" : "$N一式「龟蛇竞渡」，前手为蛇头，后手如龟头，一前一后击向$n的$l",
        "force" : 400,
        "dodge" : 15,
        "lvl" : 20,
        "skill_name" : "龟蛇竞渡",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N两掌掌心相对，交错前引，一式「倒索攀山」，五指旋转著拂向$n的$l",
        "force" : 450,
        "dodge" : 25,
        "damage": 20,
        "lvl" : 30,
        "skill_name" : "倒索攀山",
        "damage_type" : "内伤"
]),
([      "action" : "$N一式「闪现雷鸣」，左掌外旋上挑，右指内翻前指，闪点般急点$n的$l",
        "force" : 500,
        "dodge" : 30,
        "damage": 35,
        "lvl" : 40,
        "weapon": "指力",
        "skill_name" : "闪现雷鸣",
        "damage_type" : "刺伤"
]),
([      "action" : "$N单手撑地，一式「地动山摇」，翻滚著冲到$n身前，疾刺$n的下三路要害",
        "force" : 500,
        "dodge" : 35,
        "damage": 40,
        "lvl" : 60,
        "weapon": "指力",
        "skill_name" : "地动山摇",
        "damage_type" : "刺伤"
]),
([      "action" : "$N一式「水拍云崖」，左掌前推，筑起一道气墙，指力破掌而出，射向$n的$l",
        "force" : 550,
        "dodge" : 45,
        "damage": 50,
        "lvl" : 80,
        "weapon": "指力",
        "skill_name" : "水拍云崖",
        "damage_type" : "刺伤"
]),
([      "action" : "$N双指翻飞，一式「泰山压顶」，指力幻化成一个太极圈，如泰山般向$n当头压下",
        "force" : 550,
        "dodge" : 50,
        "damage": 40,
        "lvl" : 100,
        "skill_name" : "泰山压顶",
        "damage_type" : "瘀伤"
])
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }

int valid_combine(string combo) { return combo=="jinding-zhang"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练天罡指穴法必须空手。\n");
        if ((int)me->query_skill("linji-zhuang", 1) < 10)
                return notify_fail("你的临济十二庄火候不够，无法学天罡指穴法。\n");
        if ((int)me->query("max_neili") < 50)
                return notify_fail("你的内力太弱，无法练天罡指穴法。\n");
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

	if( me->query_temp("tgz_attack") )
		return ([
			"action": "$N"+ me->query_temp("weapon_name") +
				"向后甩出，左手食中二指向$n接连戳去，一连"+ chinese_number(3+random(7))
				+"指，全是对向$p头脸与前胸重穴",
			"force" : 500,
			"dodge" : 15,
			"damage": 45,
        		"damage_type" : random(2)?"内伤":"刺伤",
			"weapon": random(2)?"指力":"指劲"
			]);

        level   = (int) me->query_skill("tiangang-zhi",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("jingli") < 30)
                return notify_fail("你的精力太低了。\n");
        if ((int)me->query("neili") < 10)
                return notify_fail("你的内力不够练天罡指穴法。\n");
        me->receive_damage("jingli", 30);
        me->add("neili", -10);
        return 1;
}
