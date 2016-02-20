//Cracked by Roath

//xuanfengsaoye-tui.c
//kane 14/10/97  

inherit SKILL;


mapping *action = ({
([      "action" :"$N两手反背，双足不丁不八，使出一招「风起云涌」，左脚横空踢出，踹向$n面门，右膝撞向$n软肋",
        "force" : 120,
	"parry" : -5,
        "lvl" : 0,
        "skill_name" : "风起云涌",
        "damage_type" : "淤伤"
]),
([      "action" :"$N身形向后飞退，忽然一招「空谷足音」，关节诡异之极的一扭，右脚挟着劲风，悄无声息地踢向$n的$l",
        "force" : 150,
	"dodge" : 10,
	"parry" : -10,
        "lvl" : 8,
        "skill_name" : "空谷足音",
        "damage_type" : "挫伤"
]),
([      "action" :"$N使出小擒拿手，扣住$n手腕，向内疾夺，左脚一招「碧渊腾蛟」，无影无踪地朝$n前胸踢到",
        "force" : 200,
	"dodge" : 5,
	"parry" : -5,
        "lvl" : 15,
        "skill_name" : "碧渊腾蛟",
        "damage_type" : "挫伤"
]),
([      "action" :"$N凌空一个“千斤坠”，落地稳住身形，使出一式「秋风落叶」，左足支地，右腿绕着身子瞬息间横扫三圈，逼得$n连连后退",
        "force" : 250,
	"dodge" : 5,
	"parry" : -10,
        "lvl" : 20,
        "skill_name" : "秋风落叶",
        "damage_type" : "跌伤"
]),
([      "action" :"$N蓦地欺近$n身去，矮身飞肘撞向$n小腹，$n正待抵挡，$N变招奇速，一招「风扫残云」，沉肩拗膝，双足鸳鸯连环踢向$n的$l",
        "force" : 300,
        "dodge" : 15,
        "parry" : -10,
        "lvl" : 30,
        "skill_name" : "风扫残云",
        "damage_type" : "淤伤"
]),
([      "action" :"$N将身一纵，跃在半空，一式「流星坠地」，右脚踵撞向$n天灵，左脚横扫$n前胸，落地后双足绞向$n脚踝，一招三式，迅猛无比",
        "force" : 350,
        "dodge" : 20,
	"parry" : -15, 
        "lvl" : 40,
        "skill_name" : "流星坠地",
        "damage_type" : "跌伤"
]),
([      "action" :"$N身形飞旋撞向$n，使出一招「朔风吹雪」，$N身法忽正忽逆，腿法变幻，忽而横扫直踹，忽而勾脚反踢，尤如生了数十条手脚一般，$n顿时阵脚大乱",
	"force" : 400,
	"dodge" : 20,
	"parry" : -5,
	"lvl" : 50,
	"skill_name" : "朔风吹雪",
	"damage_type" : "跌伤"
]),
([      "action" :"$N脚下踏着五行八卦方位，蓦地一声大喝，一式「雷动九天」，刹那间向$n连攻六六三十六腿，腿影如山，$n全身要害无一幸免，势道猛恶之至",
	"force" : 450,
	"dodge" : 15,
	"parry" : -5,
	"lvl" : 60,
	"skill_name" : "雷动九天",
	"damage_type" : "挫伤"
]),
});

int valid_enable(string usage) { return usage=="kick" || usage=="parry"; }

int valid_combine(string combo) { return combo=="luoying-shenjian"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练旋风扫叶腿必须空手。\n");
	if ((int)me->query_skill("bitao-xuangong", 1) < 20)
	   return notify_fail("你的碧涛玄功火候不够，无法学旋风扫叶腿。\n");
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
	level   = (int) me->query_skill("xuanfeng-saoye",1);
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
        me->receive_damage("jingli", 25);
	me->add("neili", -5);
       
       return 1;
}

string perform_action_file(string action)
{
       return __DIR__"luoying-shenjian/" + action;
}
