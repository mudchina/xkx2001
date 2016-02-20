//Cracked by Roath
// dashou-yin 密宗大手印
// qfy, chage, paoshou Sept 26, 1996
// ryu, 11/14/96.

inherit SKILL;

mapping *action = ({
([	"action" : "$N一式「莲花合掌印」，双手向相，拇指、小指互触，面戴微笑，欺近$n的身前，印向$n的$l",
	"force" : 140,
        "dodge" : 5,
        "lvl" : 0,
        "skill_name" : "莲花合掌印",
	"damage_type" : "瘀伤"
]),
([	"action" : "紧接着$N手指交插，拇指向外微分，手结「合掌观音印」，向$n当头切下，势不可挡",
	"force" : 200,
        "dodge" : 10,
        "lvl" : 10,
        "skill_name" : "合掌观音印",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N使一式「准提佛母印」，手指交叉，食指朝天，面作沉思状，突然翻腕结手印拍向$n的$l",
	"force" : 250,
        "dodge" : 5,
        "lvl" : 20,
        "skill_name" : "准提佛母印",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N手结「红阎婆罗印」，三睛怒睁、阔嘴大张、喝一声胜乐咒，左右手一擒一拿，捉向$n的下三路",
        "force" : 280,
        "dodge" : 5,
        "lvl" : 30,
        "skill_name" : "红阎婆罗印",
        "damage_type" : "跌伤"
]),
([	"action" : "却见$N双手握拳，食指前伸，鼓足内力，结一式「药师佛根本印」，朝$n的$l擒过去",
	"force" : 320,
        "dodge" : 0,
        "lvl" : 40,
	"damage" : 30,
        "skill_name" : "药师佛根本印",
        "damage_type" : "跌伤"
]),
([	"action" : "只听得$N口中念念梵唱，神色庄严地施展「威德金刚印」，双手交叉，拇指相叠，一下扣住$n肩井大穴，抗起$n向後一摔",
	"force" : 380,
        "dodge" : 5,
        "lvl" : 50,
	"damage" : 40,
        "skill_name" : "威德金刚印",
        "damage_type" : "跌伤"
]),
([	"action" : "$N面浮微笑，双手互握，手腕相触，一步抢到$n的身前，一式「上乐金刚印」切住$n后腰，轻轻一推",
	"force" : 420,
        "dodge" : 0,
        "lvl" : 60,
	"damage" : 45,
        "skill_name" : "上乐金刚印",
        "damage_type" : "跌伤"
]),
([      "action" : "$N一式「六臂智慧印」，结跏趺坐，口念核心咒，双手一下拿住$n胳膊，左脚顺势一绊",
        "force" : 450,
        "dodge" : 5,
        "lvl" : 70,
	"damage" : 55,
        "skill_name" : "六臂智慧印",
        "damage_type" : "跌伤"
]),
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }

int valid_combine(string combo) { return combo=="yujiamu-quan"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练密宗大手印必须空手。\n");
	if ((int)me->query_skill("longxiang-banruo", 1) < 20
	&& (int)me->query_skill("xiaowuxiang", 1) < 20){
		return notify_fail("你的龙象般若功火候不够，无法学密宗大手印。\n");
	}
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练密宗大手印。\n");
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
	level   = (int) me->query_skill("dashou-yin",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30)
		return notify_fail("你的精力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练密宗大手印。\n");
	me->receive_damage("jingli", 25);
	me->add("neili", -5);
	return 1;
}
