//Cracked by Roath
// banruo-zhang.c -般若掌
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : "$N前腿踢出，后腿脚尖点地，一式「横空出世」，二掌直出，攻向$n的上中下三路",
        "force" : 150,
        "dodge" : 5,
        "damage_type" : "瘀伤",
        "lvl" : 0,
        "skill_name" : "横空出世"
]),
([      "action" : "$N左掌划一半圆，一式「长虹贯日」，右掌斜穿而出，疾拍$n的胸前大穴",
        "force" : 160,
        "dodge" : 5,
        "damage_type" : "瘀伤",
        "lvl" : 12,
        "skill_name" : "长虹贯日"
]),
([      "action" : "$N使一式「云断秦岭」，右掌上引，左掌由后而上一个甩劈，斩向$n的$l",
        "force" : 170,
        "dodge" : 5,
        "damage_type" : "劈伤",
        "lvl" : 18,
        "skill_name" : "云断秦岭"
]),
([      "action" : "$N左掌护胸，右拳凝劲后发，一式「铁索拦江」，缓缓推向$n的$l",
        "force" : 185,
        "dodge" : -5,
        "damage_type" : "瘀伤",
        "lvl" : 24,
        "skill_name" : "铁索拦江"
]),
([      "action" : "$N使一式「狂风卷地」，全身飞速旋转，双掌一前一后，猛地拍向$n的胸口",
        "force" : 200,
        "dodge" : 10,
        "damage_type" : "瘀伤",
        "lvl" : 30,
        "skill_name" : "狂风卷地"
]),
([      "action" : "$N合掌抱球，猛吸一口气，一式「怀中抱月」，双掌疾推向$n的肩头",
        "force" : 220,
        "dodge" : 5,
        "damage_type" : "瘀伤",
        "lvl" : 36,
        "skill_name" : "怀中抱月"
]),
([      "action" : "$N向上高高跃起，一式「高山流水」，居高临下，掌力笼罩$n的全身",
        "force" : 240,
        "dodge" : 20,
        "damage_type" : "瘀伤",
        "lvl" : 42,
        "skill_name" : "高山流水"
]),
([      "action" : "$N使一式「摘星换斗」，劲气弥漫，双掌如轮，一环环向$n的$l斫去",
        "force" : 270,
        "dodge" : 10,
        "damage_type" : "劈伤",
        "lvl" : 48,
        "skill_name" : "摘星换斗"
]),
([      "action" : "$N两掌上下护胸，一式「翻江搅海」，骤然化为满天掌雨，攻向$n",
        "force" : 310,
        "dodge" : 30,
        "damage_type" : "瘀伤",
        "lvl" : 54,
        "skill_name" : "翻江搅海"
]),
([      "action" : "$N一式「金刚伏魔」，双手合十，对着$n微微一揖，全身内劲如巨浪般汹涌而出",
        "force" : 360,
        "dodge" : 10,
        "damage_type" : "瘀伤",
        "lvl" : 60,
        "skill_name" : "金刚伏魔"
])
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_combine(string combo) { return combo=="yizhi-chan"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练般若掌必须空手。\n");
        if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
                return notify_fail("你的混元一气功火候不够，无法学般若掌。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练般若掌。\n");
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
	string *msg = ({
		"喝道：“吃我一掌！”",
		"双手合什，说道：“阿弥陀佛！”",
		"说道：“罪过罪过！”这四字一出口，忽地",
		"",
	});

        level = (int)me->query_skill("banruo-zhang", 1);
        if( me->query_temp("sl_perform/san") )
	{
		i = me->query_skill("force") + level;
		return([      
			"action": HIW"$N"+ msg[random(sizeof(msg))] +"双掌自外向里转了个圆圈，缓缓向$n推了过来。"
					"$P掌力未到，$n已感胸口呼吸不畅，顷刻之间，$N的掌力如怒潮般汹涌而至！"NOR,         
			"force" : i + random(i),
			"dodge" : -100,
			"damage_type" : "瘀伤", ]);
	}
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("jingli") < 30)
                return notify_fail("你的精力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练般若掌。\n");

        if( (int)me->query_skill("nianhua-zhi", 1) < 150 )
                return notify_fail("你的拈花指修为还不够。\n");

        me->receive_damage("jingli", 25);
        me->add("neili", -5);
        return 1;
}

void skill_improved(object me)
{
        int level = (int)me->query_skill("banruo-zhang", 1);

        if( level >= 180
        &&  (int)me->query_skill("yizhi-chan", 1) >= 180
        &&  !me->query("sl_gifts/yzc") ) {
                me->add("con", 1);
                me->set("sl_gifts/yzc", 1);
                write("\n你的一指禅和般若掌学有所成，提高了你的根骨。\n");
        }

        if( !(level % 10) && level >= (int)me->query_skill("force", 1) ) {
                me->improve_skill("force", (level - 5), 1);
                write("\n你在般若掌方面的造诣增进了你的基本内功修为。\n");
        }

        if( !(level % 10) && level >= (int)me->query_skill("hunyuan-yiqi", 1) ) {
                me->improve_skill("hunyuan-yiqi", (level - 5)/2, 1);
                write("\n你在般若掌方面的造诣增进了你的混元一气功修为。\n");
        }              
}

string perform_action_file(string action)
{
        return __DIR__"banruo-zhang/" + action;
}
