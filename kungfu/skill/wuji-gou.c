//Cracked by Roath
// wuji-gou.c 无极钩法
// snowbird august 99
// 1.1.1.1

inherit SKILL;

mapping *action = ({
([      "action" : "$N手中$w骤的用力往下一沉，一式“雪泥鸿爪”，倏地挑向$n的$l",
        "force" : 100,
        "dodge" : 20,
        "damage" : 15,
        "lvl" : 0,
        "damage_type" : "刺伤"
]),
([      "action" : "$N连人带$w一转，斜掠过去，一式“三羊开泰”，刺胸膛，挂两肩，狠狠地扫了过去",
        "force" : 150,
        "dodge" : 15,
        "damage" : 30,
        "lvl" : 20,
        "damage_type" : "砍伤"
]),
([      "action" : "$N如影附形，一招“野马分鬃”，$w便如无风海雨，连绵不断地朝$n直攻过来",
        "force" : 200,
        "dodge" : 10,
        "damage" : 45,
        "lvl" : 40,
        "damage_type" : "砍伤"
]),
([      "action" : "$N把$w一挽，划了一个圆圈，一记“弯弓射雕”，左右开弓，打将过去",
        "force" : 250,
        "dodge" : 15,
        "damage" : 60,
        "lvl" : 60,
        "damage_type" : "砍伤"
]),
([      "action" : "$N一招“金蛇狂舞”，手中$w直抖开来，舞成一道丈许方圆的钩花，当头罩下",
        "force" : 300,
        "dodge" : 15,
        "damage" : 75,
        "lvl" : 80,
        "damage_type" : "割伤"
]),
([      "action" : "$N旋风般直卷过去，$w一招“力划鸿沟”，自上而下，奋力劈去",
        "force" : 350,
        "dodge" : 20,
        "damage" : 90,
        "lvl" : 100,
        "damage_type" : "砍伤"
]),
([      "action" : "$N纵身跃起，就在空中一招“鹏搏九霄”，凌空下划，$w直斩$n要害",
        "force" : 400,
        "dodge" : 20,
        "damage" : 105,
        "lvl" : 120,
        "damage_type" : "砍伤"
]),
([      "action" : "$N$w一抽，使一招“大漠苍龙”顺势反斩，疾如骇电奔雷，取向$n$l",
        "force" : 450,
        "dodge" : 20,
        "damage" : 120,
        "lvl" : 140,
        "damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return (usage == "hook") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 150)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("hongming-xuangong", 1) < 20)
                return notify_fail("你的鸿冥玄功火候太浅。\n");
        if ((int)me->query_skill("hook", 1) < 20)
                return notify_fail("你的钩法基本功还不扎实。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        mapping retval;
		int i, j, level, neili;
        level  = (int) me->query_skill("wuji-gou",1);

        for(i = sizeof(action); i > 0; i--) { 
                if(level > action[i-1]["lvl"]) {
                      j = NewRandom(i, 20, level/5);
                      break;
                }
		}
		retval = action[j];
		if (random(me->query_skill("hook")) > 150 
            && me->query_skill("force") > 100  && me->query("neili") > 500 ) {
			retval["damage"] = retval["damage"] + me->query_skill("force")/5;
		}
        return retval;
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "hook")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("jingli") < 40)
                return notify_fail("你的精力不够练无极钩法。\n");
        me->receive_damage("jingli", 30);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"wuji-gou/" + action;
}

mapping *query_skilldbase() {return action;}
