//Cracked by Roath
// duanyun-bian.c 断云鞭法
// sdong 09/98

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action":               "$N使一招「聚火」，手中$w在空中转了一圈，忽然对准$n的胸腹要害连刺数下",
        "dodge":                -5,
        "damage":               60,
        "force" :               160,
        "lvl" :                 0,
        "skill_name" : "聚火",
        "damage_type":  "鞭伤"
]),
([      "action":               "$N力贯鞭梢，一招「起光」，手中$w闪出火光，猛地向$n劈头打下",
        "dodge":                -10,
        "damage":                95,
        "force" :               320,
        "lvl" :                 10,
        "skill_name" : "起光",
        "damage_type":  "鞭伤"
]),
([      "action":               "$N身形一转，使出一式「招雨」，手中$w舞出满天鞭影，如暴风雨般扫向$n全身",
        "dodge":                -15,
        "damage":               120,
        "force" :               480,
        "lvl" :                 20,
        "skill_name" : "招雨",
        "damage_type":  "鞭伤"
]),
([      "action":               "$N一招「动雷」，手中$w夹带风雷之声，排山倒海般打向$n全身",
        "dodge":                -15,
        "damage":               110,
        "force" :               380,
        "lvl" :                 30,
        "skill_name" : "动雷",
        "damage_type":  "鞭伤"
]),
([      "action":               "$N身形一转，一招「移电」，手中$w如鬼魅一般，神不知鬼不觉地袭向$n",
        "dodge":                -10,
        "damage":                90,
        "force" :               300,
        "lvl" :                 40,
        "skill_name" : "移电",
        "damage_type":  "鞭伤"
]),
([      "action":               "$N一纵身，一招「剪虹」，手中$w迅猛无比地向$n劈头打下",
        "dodge":                -10,
        "damage":                95,
        "force" :               300,
        "lvl" :                 50,
        "skill_name" : "剪虹",
        "damage_type":  "鞭伤"
]),
([      "action":               "$N左手虚晃，右脚忽然迈出一大步，一招「止风」，手中$w无声无息地击向$n",
        "dodge":                -10,
        "damage":                75,
        "force" :               300,
        "lvl" :                 60,
        "skill_name" : "止风",
        "damage_type":  "鞭伤"
]),
([      "action":               "$N暗运神功，将内力贯注$w，一招「断云」，手中$w以雷霆万钧之势，猛地向$n扫去",
        "dodge":                -10,
        "damage":                120,
        "force" :               420,
        "lvl" :                 70,
        "skill_name" : "断云",
        "damage_type":  "鞭伤"
]),
([      "action":               "$N使劲一甩，使出一招「遮月」，黑暗中只见$w闪出一丝光芒，从不可思议的角度往$n身上落下!",
        "dodge":                -10,
        "damage":                130,
        "force" :               520,
        "lvl" :                 120,
        "skill_name" : "遮月",
        "damage_type":  "鞭伤"
]),
([      "action":               "$N用力一跃，在半空中施展出「掩日」，煞那间，天昏地暗，你手中的$w从半空中往$n直击而下",
        "dodge":                -10,
        "damage":                150,
        "force" :               670,
        "lvl" :                 150,
        "skill_name" : "掩日",
        "damage_type":  "鞭伤"
])
});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

int valid_learn(object me)
{
        mapping fam;
        object weapon;


        if( (int)me->query("max_neili") < 500 )
                return notify_fail("你的内力不足，没有办法练断云鞭法，多练些内力再来吧。\n");

        if ((int)me->query_skill("xiantian-gong", 1) < 50)
                return notify_fail("你的先天功火候太浅。\n");

        if ( !objectp(weapon = me->query_temp("weapon"))
        || ( string)weapon->query("skill_type") != "whip" )
                return notify_fail("你必须先找一条鞭子才能练鞭法。\n");

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
        level   = (int) me->query_skill("duanyun-bian",1);
                  for(i = sizeof(action); i > 0; i--)
                                         if(level > action[i-1]["lvl"])
                                                                return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "whip")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("jingli") < 50)
                return notify_fail("你的精力不够练断云鞭法。\n");
        me->receive_damage("jingli", 10 );
        if( me->query_skill("duanyun-bian",1) > 150 ) me->receive_damage("jingli", 5 );
        if( me->query_skill("duanyun-bian",1) > 180 ) me->receive_damage("jingli", 10 );
        if( me->query_skill("duanyun-bian",1) > 200 ) me->receive_damage("jingli", 15 );

        return 1;
}

string perform_action_file(string action)
{
        if ( this_player()->query_skill("duanyun-bian", 1) >= 50 )
                return __DIR__"duanyun-bian/" + action;
}
