//Cracked by Roath
// wuxingbu.c 
//kane

inherit SKILL;

mapping *action = ({
([	"action" : "$n一个「旱地拔葱」，向上窜起数尺，避过$N攻击。\n",
	"dodge"  : 10
]),
([	"action" : "$n一个「鹞子翻身」，凌空一个侧翻，闪过了$N的凌厉攻势。\n",
	"dodge"  : 20
]),
([	"action" : "$n见势不妙，不得以使招「懒驴打滚」，往地上一滚，躲过$N的攻击。\n",
	"dodge"  : 30
]),
});

mapping query_action(object me, object weapon)
{
	int zhaoshu, level;

	zhaoshu = sizeof(action);
	level   = (int) me->query_skill("wuxingbu");

	return action[random(zhaoshu)];
}

int valid_enable(string usage)
{
	return usage == "dodge" || usage == "move";
}

int valid_learn(object me)
{
	return 1;
}

string query_dodge_msg(string limb)
{
// The following codes are buggy, because "me" is the attacker instead
// of defender.
/*
	object me, ob;
	mapping action;

	me = this_player();
	action = query_action(me, ob);

	return action["action"];
*/
        return action[random(sizeof(action))]["action"];
}

int practice_skill(object me)
{

	return notify_fail("你不能练五形步。\n");
}
