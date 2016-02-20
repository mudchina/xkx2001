//Cracked by Roath
// zhutian-bu.c 诸天化身步

inherit SKILL;

mapping *action = ({
([	"action" : "$n一招「天地钩」，两脚脚尖前踢，一个空心筋斗，向前翻出丈外。\n",
	"dodge"  : 10,
	"skill_name" : "天地钩"
]),
([	"action" : "$n一招「凤点头」，全身顿时象没了脊梁般往后倒折，$N的招势全打在空处。\n",
	"dodge"  : 20,
	"skill_name" : "凤点头"
]),
([	"action" : "$n一招「鹰爪松」，腾空一跃，在空中一转，双手抓地，倒立起来。\n",
	"dodge"  : 30,
	"skill_name" : "鹰爪松"
]),
([	"action" : "$n一招「风摆柳」，柔若无骨般随著$N的攻击上下左右摇摆不定，令$N无从下手。\n",
	"dodge"  : 40,
	"skill_name" : "风摆柳"
]),
([	"action" : "$n一招「阴阳箭」，双足一顿，全身笔直地拔地而起，箭一般射到几丈远的地方。\n",
	"dodge"  : 50,
	"skill_name" : "阴阳箭"
]),
([	"action" : "$n一招「日月扣」，突然化身为二，分居$N的左右两侧，联合向$N进击。\n",
	"dodge"  : 60,
	"skill_name" : "日月扣"
]),
});

string query_skill_name(int level)
{
	int zhaoshu = random(level/10);
	
	if ( zhaoshu >= sizeof(action) ) zhaoshu = sizeof(action)-1;

	return action[zhaoshu]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int zhaoshu, level;

	zhaoshu = sizeof(action);
	level   = (int) me->query_skill("zhutian-bu");

	if (level < 60 )
		zhaoshu--;

	if (level < 50 )
		zhaoshu--;

	if (level < 40 )
		zhaoshu--;

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
	if( (int)me->query("jingli") < 30 )
		return notify_fail("你的精力太差了，不能练诸天化身步。\n");
	me->receive_damage("jingli", 30);
	return 1;
}
