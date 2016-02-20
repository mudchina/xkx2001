//Cracked by Roath
// liumai-shenjian.c 六脉神剑  changed by macmac

inherit SKILL;
mapping *action = ({
([      "action" : "$N左手小指点出，使一招「少泽剑」，无形剑气忽来忽去，变化精微，内力自左向右的向$n斜攻",
        "force" : 300,
        "dodge" : 15,
        "damage": 350,
        "lvl" : 22,
        "skill_name" : "少泽剑",
	"weapon": "无形剑气",
        "damage_type" : "刺伤"
]),
([      "action" : "$N右手小指一点，正是「少冲剑」，一条气流从少冲穴中激射而出，工拙捷缓不定，令人实难捉摸",
        "force" : 330,
        "dodge" : 20,
        "damage": 400,
        "lvl" : 36,
        "skill_name" : "少冲剑",
	"weapon": "无形剑气",
        "damage_type" : "刺伤"
]),
([      "action" :"$N运起真气，「关冲剑」使出，剑气拙滞古朴，无名指点处，嗤嗤声响，真气汹涌并发",
        "force" : 360,
        "dodge" : 25,
        "damage": 450,
        "lvl" : 52,
        "skill_name" : "关冲剑",
	"weapon": "无形剑气",
        "damage_type" : "刺伤"
]),
([      "action" : "$N中指轻弹，使出了「中冲剑」，大开大阖，气势雄迈，一路剑法使来结构严谨，全无破绽",
        "force" : 400,
        "dodge" : 30,
        "damage": 500,
        "lvl" : 70,
        "skill_name" : "中冲剑",
	"weapon": "无形剑气",
        "damage_type" : "刺伤"
]),
([      "action" : "$N食指点出，变成了「商阳剑」，轻灵迅速，食指连动，一剑又一剑的刺出，巧妙活泼，难以捉摸",
        "force" : 450,
        "dodge" : 35,
        "damage": 550,
        "lvl" : 90,
        "skill_name" : "商阳剑",
	"weapon": "无形剑气",
        "damage_type" : "刺伤"
]),
([      "action" : "$N大拇指按出，使动「少商剑」，剑法大开大阖，气派宏伟，便如是一幅泼墨山水相似，纵横倚斜，寥寥数笔，却是剑路雄劲，每一剑刺出，都有石破天惊、风雨大至之势",
        "force" : 600,
        "dodge" : 50,
        "damage": 600,
        "lvl" : 130,
        "skill_name" : "少商剑",
	"weapon": "无形剑气",
        "damage_type" : "刺伤"
])
});
 int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练六脉神剑必须空手。\n");
        if ((int)me->query_skill("force", 1) < 180)
                return notify_fail("你的内力修为还不够深厚。\n");
        if ((int)me->query("max_neili") < 2000)
                return notify_fail("你尚未修聚到如此强劲浑厚的内力！\n");
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
        level   = (int) me->query_skill("6mai-shenjian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}


int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练六脉神剑。\n");
        me->receive_damage("qi", 30);
        me->add("neili", -10);
        return 1;
} 
string perform_action_file(string action)
{
        return __DIR__"liumai-shenjian/" + action;
}

