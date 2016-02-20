//Cracked by Roath
// tiyunzong.c 梯云纵
// xQin 4/99

inherit SKILL;

mapping *action = ({
([	"action" : "$p吸一口气，猛地里双脚一撑，提身而起。\n",
	"dodge"  : 10,
]),
([	"action" : "危急中$p提一口真气，双臂急振，上窜丈余。\n",
	"dodge"  : 20,
]),
([	"action" : "$p向后纵出，便如头大鸟一般，稳稳的飞出数丈之外。\n",
	"dodge"  : 30,
]),
([	"action" : "$p当即纵身高跃，一转一折，轻轻巧巧的落在一旁。\n",
	"dodge"  : 40,
]),
([	"action" : "但$p变招奇速，右足向前踢出，身子已然腾起，轻轻巧巧的跨过了$P。\n",
	"dodge"  : 50,
]),
([	"action" : "$p一声清啸，拔身而起，在半空中轻轻一个转折，飘然落在丈许之外。\n",
	"dodge"  : 60,
]),
([	"action" : "陡然间$p身形拔起，在空中急速盘旋，连转四个圈子，愈转愈高，又是一个转折，轻轻巧巧的落在数丈之外。\n",
	"dodge"  : 70,
])
});

mapping query_action(object me, object weapon)
{
	int zhaoshu, level;

	zhaoshu = sizeof(action);
	level = (int)me->query_skill("tiyunzong");

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
	return action[random(sizeof(action))]["action"];
}

int practice_skill(object me)
{
	if( (int)me->query("jingli") < 30 )
		return notify_fail("你的精力太差了，无法练习梯云纵。\n");
	me->receive_damage("jingli", 30);
	return 1;
}
