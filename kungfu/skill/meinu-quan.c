//Cracked by Kafei
// meinu-quan.c 美女拳法
// shizika 8/5/97

inherit SKILL;

mapping *action = ({
([	"action" : "$N左手一探，一招「貂蝉拜月」，从$n肩头绕了过去，直向$n的$l斩下",
	"force" : 380,
	"dodge" : 30,
      "parry" : 30, 
	"lvl" : 80,
	"skill_name" : "貂蝉拜月",
	"damage_type" : "瘀伤"
]),
([      "action" : "$N一招「西施捧心」，双手向内一圈，左拳对准$n的心口直击而出",
        "force" : 400,
        "dodge" : 15,
        "parry" : 40,
	  "lvl" : 90,
        "skill_name" : "西施捧心",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N作个弹琵琶的姿势，左手斜举，右手五指弹起，一招「昭君出塞」根根手指向$n的$l弹去",
        "force" : 360,
        "dodge" : 25,
        "parry" : 30,
	  "lvl" : 75,
        "skill_name" : "昭君出塞",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N侧身一闪，一招「麻姑献寿」双手合拳向上抬击$n的$l",
        "force" : 300,
        "dodge" : 15,
        "parry" : 10,
        "lvl" : 70,
        "skill_name" : "麻姑献寿",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N右手挥左，左手送右，作个掷梭织布状，一招「天孙织锦」，一挥一送间，双手分击$n的$l",
        "force" : 320,
        "dodge" : 10,
        "parry" : -10,        
	  "lvl" : 68,
        "skill_name" : "天孙织锦",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N举手作提铛斟酒之状，一招「文君当垆」，向$n的$l一凿",
        "force" : 270,
        "dodge" : 20,
        "lvl" : 50,
        "skill_name" : "文君当垆",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N身子摇晃，跌跌撞撞的向右歪斜出去，一记「贵妃醉酒」肩头向$n的$l撞去",
        "force" : 350,
        "dodge" : 35,
        "lvl" : 85,
        "skill_name" : "贵妃醉酒",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N左手置于面前，右手空握成拳一招「弄玉吹箫」，向下侧击$n的$l",
        "force" : 200,
        "parry" : -10,
        "lvl" : 20,
        "skill_name" : "弄玉吹箫",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N身形飘逸，有若流风回雪，迎着$n的攻势飘然进击，正是一式「洛神凌波」",
        "force" : 320,
        "dodge" : 25,
        "lvl" : 65,
        "skill_name" : "洛神凌波",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N一招「钩弋握拳」双拳收于腰际，向前平推而出，攻向$n的$l",
        "force" : 200,
        "dodge" : 15,
        "lvl" : 40,
        "skill_name" : "钩弋握拳",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N一式「则天垂帘」，身子前扑，双掌以垂帘式向$n的$l直削而下",
	"force" : 280,
	"dodge" : 30,
        "lvl" : 55,
	"skill_name" : "则天垂帘",
        "damage_type" : "内伤"
]),
([	"action" : "$N一招「红玉击鼓」欺身上前，双臂交互向$n的$l快击而去",
	"force" : 150,
	"dodge" : 25,
        "lvl" : 30,
	"skill_name" : "红玉击鼓",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N突然出其不意的叩关直入，一记「红拂夜奔」连人带拳向$n直冲而至",
	"force" : 180,
	"dodge" : 20,
        "lvl" : 25,
	"skill_name" : "红拂夜奔",
        "damage_type" : "内伤"
]),
([	"action" : "$N忽地向下俯冲，一式「绿珠坠楼」扑地向$n的下盘攻去",
	"force" : 190,
	"dodge" : 15,
        "lvl" : 20,
	"skill_name" : "绿珠坠楼",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N一招「文姬归汉」双掌连拍数下，接着掌出连绵，罩住$n的全身",
        "force" : 270,
        "parry" : 20,
        "lvl" : 45,
        "skill_name" : "文姬归汉",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N左手作掩门状，右手向后轻挥，一招「红线盗盒」击向$n的$l",
        "force" : 130,
        "dodge" : 10,
        "lvl" : 15,
        "skill_name" : "红线盗盒",
        "damage_type" : "抓伤"
]),
([      "action" : "$N向前跨出一个箭步，一招「木兰弯弓」，右手后引，左手疾向前按向$n的$l",
        "force" : 250,
        "parry" : 15,
        "lvl" : 35,
        "skill_name" : "木兰弯弓",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N一式「班姬赋诗」双手向后作背手状，接着抬手击向$n的胸腹，同时借力向前飘出",
        "force" : 100,
        "parry" : -10,
        "lvl" : 10,
        "skill_name" : "班姬赋诗",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N使一招「嫦娥窃药」，衣袂飘飘，双手交错锁拿$n的$l",
        "force" : 300,
        "paryy" : 20,
        "lvl" : 64,
        "skill_name" : "嫦娥窃药",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N腰肢轻摆，脸上忽现书卷之气，一式「蛮腰纤纤」，袖中藏掌挥向$n的$l",
        "force" : 50,
        "dodge" : 60,
        "lvl" : 37,
        "skill_name" : "蛮腰纤纤",
        "damage_type" : "内伤"
]),
([      "action" : "$N微微一笑，五指张开，伸手在头发上一梳，顺势挥向$n的$l，却是一招「丽华梳妆」",
        "force" : 150,
        "dodge" : 10,
        "lvl" : 0,
        "skill_name" : "丽华梳妆",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N左手一引一带，一招「萍姬针神」，骈指刺向$n的$l",
        "force" : 160,
        "dodge" : 5,
        "lvl" : 5,
        "skill_name" : "萍姬针神",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N突使一招「曹令割鼻」，手掌在自己面前削过，劈向$n的$l",
        "force" : 80,
        "parry" : 70,
        "lvl" : 18,
        "skill_name" : "曹令割鼻",
        "damage_type" : "瘀伤"
])
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }

int valid_combine(string combo) { return combo=="tianluo-diwang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练美女拳法必须空手。\n");
	if ((int)me->query_skill("yunu-xinjing", 1) < 20)
		return notify_fail("你的玉女心经火候不够，无法学美女拳法。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练美女拳法。\n");
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
        level  = (int)me->query_skill("meinu-quan", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30)
		return notify_fail("你的精力太低了。\n");
	if ((int)me->query("neili") < 10)
		return notify_fail("你的内力不够练美女拳。\n");
        me->receive_damage("jingli", 25, "精力透支过度死了。");
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"meinu-quan/" + action;
}
