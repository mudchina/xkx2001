//Cracked by Roath
// jiangshi-bu.c
// qfy July 8, 1996

inherit SKILL;

mapping *action = ({
([	"action" : "$n直挺挺的往後一纵，避开了$N的凌厉攻势。\n",
	"dodge"  : 10
]),
([	"action" : "$n直挺挺的往左一跳，化解了$N的攻势。\n",
	"dodge"  : 20
]),
([	"action" : "$n身形一飘，突然到了$N的身后。\n",
	"dodge"  : 30
]),
([	"action" : "$n硬生生笔直跃起，将$N的攻势化于无形。\n",
	"dodge"  : 40
]),
([	"action" : "$n突然往右一跃，闪到一旁。\n",
	"dodge"  : 50
]),
([	"action" : "$n突然向後一倒，避过了$N的攻势，又僵直的蹦了站起。\n",
	"dodge"  : 60
])
});

mapping query_action(object me, object weapon)
{
	int zhaoshu, level;

	zhaoshu = sizeof(action);
	level   = (int) me->query_skill("jiangshi-bu");

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

string query_dodge_msg(string limb)
{
	object me, ob;
	mapping action;

	me = this_player();
	action = query_action(me, ob);

	return action["action"];
}