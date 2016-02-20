//Cracked by Roath
//luoyingshenjian-zhang.c
//kane 14/10/97  

#include <ansi.h>
#include <combat.h>

inherit SKILL;

mapping *action = ({
([      "action" :"$N跨前一步，双掌陡然间一错，右掌拂胸，左掌斜飞，正是一招「春云乍展」，击向$n的$l",
        "force" : 150,
        "dodge" : 0, 
        "parry" : -10, 
        "damage": 15,
        "lvl" : 0,
        "skill_name" : "春云乍展",
        "damage_type" : "淤伤"
]),
([      "action" :"$N沉肩拗步，缩掌回肘，使出一招「回风拂柳」，掌力虽不甚强劲，但却如春风扑面，无孔不入，推向$n面门",
        "force" : 180,
        "dodge" : 10, 
        "parry" : -5, 
        "damage": 20,
        "lvl" : 8,
        "skill_name" : "回风拂柳",
        "damage_type" : "内伤"
]),
([      "action" :"$N左足一点，跃起丈余，一式「江城飞花」，在半空中连转两个圈子，凌空挥掌，向$n当头击到",
        "force" : 220,
        "dodge" : 25, 
        "parry" : -5, 
        "damage": 25,
        "lvl" : 16,
        "skill_name" : "江城飞花",
        "damage_type" : "淤伤"
]),
([      "action" :"$N蓦地欺近身去，使出一招「雨急风狂」，变招奇速，双掌锋锐如剑，向$n连劈五五二十五掌，$n登时手忙脚乱",
        "force" : 250,
        "dodge" : 20, 
        "parry" : -15, 
        "damage": 30,
        "lvl" : 24,
        "skill_name" : "雨急风狂",
        "damage_type" : "劈伤",
	"weapon" : "掌锋"
]),
([      "action" :"$N深吸一口长气，双掌之间真气鼓荡，陡然一分，一招「星河在天」，一道弧形掌劲猛然击向$n的$l",
        "force" : 290,
        "dodge" : 15, 
        "parry" : -5, 
        "damage": 35,
        "lvl" : 32,
        "skill_name" : "星河在天",
	"weapon" : "掌劲",
        "damage_type" : "刺伤"
]),
([      "action" :"$N双臂微扬，掌力吞吐不定，正是一招「流华纷飞」，只见$N双臂挥动，四面八方都是掌影，迅捷无伦地击向$n",
        "force" : 330,
        "dodge" : 20, 
        "parry" : -10, 
        "damage": 40,
        "lvl" : 40,
        "skill_name" : "流华纷飞",
	"weapon" : "掌力",
        "damage_type" : "刺伤"
]),
([      "action" :"$N微微一笑，使出一招「彩云追月」，右掌在身前划过，掌力流转，护住全身，突然左掌后发先至，呼地一声，无影无踪地击向$n的$l",
        "force" : 380,
        "dodge" : 25, 
        "parry" : -10, 
        "damage": 45,
        "lvl" : 48,
        "skill_name" : "彩云追月",
        "damage_type" : "淤伤"
]),
([      "action" :"$N手臂微扬，突然呼地一掌自头顶击落，正是一式「天如穹庐」，掌力广被，身周一丈方圆，尽在其笼罩之下",
        "force" : 400,
        "dodge" : 10, 
        "parry" : 25, 
        "damage": 50,
        "lvl" : 56,
        "skill_name" : "天如穹庐",
        "damage_type" : "内伤"
]),
([      "action" :"$N五指并拢，气凝掌缘，一招「朝云横度」，化掌为剑，掌风过处，嗤嗤作响，电光石火般向$n拦腰横削过来",
        "force" : 350,
        "dodge" : 25, 
        "parry" : -5, 
        "damage": 60,
        "lvl" : 64,
        "skill_name" : "朝云横度",
	"weapon" : "掌风",
        "damage_type" : "刺伤"
]),
([      "action" :"$N吐气扬声，使出一招「白虹经天」，左掌掌力疾吐，击向$n眉心，堪堪击到，右掌顺势一带，掌力一弯，曲直如意，转击$n的$l",
        "force" : 390,
        "dodge" : 20, 
        "parry" : -5, 
        "damage": 70,
        "lvl" : 72,
        "skill_name" : "白虹经天",
        "damage_type" : "淤伤"
]),
([      "action" :"$N气凝丹田，脚下踩出九宫八卦方位，双掌缓缓提起，一式「紫气东来」，劲在掌先，推向$n的$l，内力到处，双掌竟似有一层白雾笼罩",
        "force" : 450,
        "dodge" : -20, 
        "parry" : 30, 
        "damage": 80,
        "lvl" : 80,
        "skill_name" : "紫气东来",
        "damage_type" : "内伤"
]),
([      "action" :"$N一声清啸，内力急催，使出一式「落英漫天」，但见掌势纷飞，或七虚一实，或九虚一实，出掌凌厉如剑，身法飘逸若仙，$n全身要害无一处不受攻击",
        "force" : 420,
        "dodge" : 25, 
        "parry" : -10, 
        "damage": 90,
        "lvl" : 90,
	"weapon" : "掌风",
        "skill_name" : "落英漫天",
        "damage_type" : "刺伤"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_combine(string combo) { return combo=="xuanfeng-saoye"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练落英神剑掌必须空手。\n");
        if ((int)me->query_skill("bitao-xuangong", 1) < 20)
          return notify_fail("你的碧涛玄功火候不够，无法学落英神剑掌。\n");
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
        level   = (int) me->query_skill("luoying-shenjian",1);
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
