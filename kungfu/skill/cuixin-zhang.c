//Cracked by Roath
//摧心掌
//Ryu 
// 16th-Aug-2000 modified by yasuko

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([	"action" : "$N攸地变爪为掌，身形不动，右臂陡长，「忽」的一掌朝$n$l劈去",
        "force" : 220,
        "dodge" : 420,
        "lvl" : 0,
	"damage_type" : "割伤"
]),
([      "action" : "$N乘势疾上，双臂直上直下，飘忽不定。跟着大喝一声，双掌同时推出",
        "force" : 330,
        "dodge" : 450,
	"lvl" : 40,
	"damage_type" : "内伤"
]),
([	"action" : "$N双掌不住地舞动，只听「喀喇」一声轻响，右掌一立，左掌已向$n$l击去",
	"force" : 400,
        "dodge" : 420,
	"lvl" : 80,
        "damage_type" : "淤伤"
]),
([	"action" : "$N身形挫动，风声虎虎，接着朝$n连发数掌，一掌快似一掌，一掌猛似一掌",
	"force" : 450,
        "dodge" : 480,
	"lvl" : 120,
        "damage_type" : "内伤"
]),
([	"action" : "$N一声长啸，形如飘风，左掌已如风行电挚般拍出，掌未到，风先至，迅猛已极",
	"force" : 550,
        "dodge" : 430,
	"lvl" : 160,
        "damage_type" : "内伤"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_combine(string combo) { return combo=="jiuyin-zhao"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练摧心掌必须空手。\n");
	if ((int)me->query("max_neili") < 500)
		return notify_fail("你的内力太弱，无法练摧心掌。\n");
	if (me->query("family/master_name") !="周芷若")
		return notify_fail("摧心掌只能向周芷若学习或者自行领悟修炼。\n");
        if (me->query("jiuyin/corpse_poison")>151740) {
                if (me->query("jing")<=50) return notify_fail("你的精神状况太差了。\n");
                me->set("jing", 1);
		return notify_fail("你发现周芷若的讲解与自己修炼的方法格格不入，虽然搅尽了脑汁，仍是丝毫无法理解。\n");
        }
        if (random(me->query("jiuyin/corpse_poison"))>1681) {
                if (me->query("jing")<=300/(int)me->query("int")) return notify_fail("你的精神状况太差了。\n");
                me->receive_damage("jing", 300/(int)me->query("int"));
		return notify_fail("你听着周芷若的讲解，总觉得有些不对劲。\n");
        }
	return 1;
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	return notify_fail("没有九阴真经，不能自行领悟或修炼摧心掌。\n");
}
