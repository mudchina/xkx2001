//Cracked by Roath
///kungfu/skill/gumu-shenfa.c 古墓身法
// sdong 07/24/98

inherit SKILL;

mapping *action = ({
([	"action" : "$n身形飘然而起，手指轻弹，宛如仙女“采薇”，$N所发招数尽数落空。\n",
	"dodge"  : 10,
	"skill_name" : "采薇"
]),
([	"action" : "$n身形拔地而起，使出一招“散花”，长袖飞舞，$N只觉眼花撩乱，攻势全失。\n",
	"dodge"  : 20,
	"skill_name" : "散花"
]),
([	"action" : "$n身形一纵，跃在半空，在空中翻了一翻，一招“投香”，飘然落在$N身后\n",
	"dodge"  : 30,
	"skill_name" : "投香"
]),
([	"action" : "$n眼见敌招攻来，身子轻轻一侧，忽然一招“寄梅”，手指往前虚晃，状似梅花，$N一慌，招数顿时失了准头。\n",
	"dodge"  : 40,
	"skill_name" : "寄梅"
]),
([	"action" : "$n清啸一声，纵身一跃，腾空飞起数丈，一式“夺锦”，尽数避开$N的攻击\n",
	"dodge"  : 50,
	"skill_name" : "夺锦"
]),
([	"action" : "$n身形一闪，一式“映雪”，回眸一笑，当真是人美如玉，正好避开$N的凌厉攻击。\n",
	"dodge"  : 60,
	"skill_name" : "映雪"
]),
([	"action" : "$n身形晃动，长裙飞舞，若有若无的闪过$N攻击。\n",
	"dodge"  : 70,
	"skill_name" : "书裙"
]),
([	"action" : "$n身形飘然而起，使出一招“飞天”，长袖飘飘，姿态灵逸，闪过$N攻击。\n",
	"dodge"  : 80,
	"skill_name" : "飞天"
])
});

mapping query_action(object me, object weapon)
{
	int zhaoshu, level;

	zhaoshu = sizeof(action);
	level   = (int) me->query_skill("gumu-shenfa");

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
	if( (int)me->query("jingli") < 40 )
		return notify_fail("你的精力太差了，不能练古墓身法。\n");
	me->receive_damage("jingli", 30);
	return 1;
}
