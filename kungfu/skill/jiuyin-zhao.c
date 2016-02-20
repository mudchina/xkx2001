//Cracked by Roath
// jiuyin-zhua.c -九阴白骨爪
// xbc: 02/02/1997 modifyied by xuy
// 16th-Aug-2000 modified by yasuko
// haowen 10/10/00 change learn limit below 40 to fix skin bug

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([	"action" : "$N双手微张，十根尖尖的指甲映出灰白光芒，突然翻腕出爪，五指猛地插落",
	"force" : 280,
        "dodge" : 470,
	"lvl" : 0,
	"weapon": "五根手指",
	"damage_type" : "刺伤"
]),
([	"action" : "$N左手突然在$n眼前上围下钩，左旋右转，连变了七八般，蓦地里右手一伸，五根手指直插$n$l",
	"force" : 320,
        "dodge" : 460,
	"lvl" : 40,
	"weapon": "五根手指",
        "damage_type" : "刺伤"
]),
([	"action" : "但听「喀喇」一响，$N的手臂斗然长了半尺，一掌按向$n$l，五指即要插进",
	"force" : 480,
        "dodge" : 450,
	"lvl" : 80,
	"weapon": "五根手指",
        "damage_type" : "刺伤"
]),
([	"action" : "突然人影闪动，$N已飞身迫到$n身后，探手出袖，五指伸张，疾向$n$l插去",
	"force" : 500,
        "dodge" : 480,
	"lvl" : 120,
	"weapon": "五根手指",
        "damage_type" : "刺伤"
]),
([	"action" : "只听$N一声清叱，左手径向$n$l抓去，跟着手肘撞向$n胸口穴道，右手箕张，五指竟已虚悬在$n头顶",
	"force" : 600,
        "dodge" : 500,
	"lvl" : 160,
	"weapon": "五根手指",
        "damage_type" : "刺伤"
]),
});

int valid_enable(string usage) { return usage=="claw" || usage=="parry"; }

int valid_combine(string combo) { return combo=="cuixin-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练九阴白骨爪必须空手。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练九阴白骨爪。\n");
	if
((me->query("family/master_name") !="周芷若")&&(me->query_skill("jiuyin-zhao",1) >
40))
		return notify_fail("九阴白骨爪只能向周芷若学习或者自行领悟修炼。\n");
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
	return notify_fail("没有九阴真经，不能自行领悟或修炼九阴白骨爪。\n");
}
string perform_action_file(string action)
{
        return __DIR__"jiuyin-zhao/" + action;
}
