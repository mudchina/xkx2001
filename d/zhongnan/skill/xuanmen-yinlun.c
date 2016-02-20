//Cracked by Roath
///kungfu/skill/xuanmen-yinlun.c 玄门隐沦
// sdong 07/24/98

inherit SKILL;

mapping *action = ({
([	"action" : "$n将头一低，身形疾闪，正是一招“藏形匿迹”，$N所发招数尽数落空。\n",
	"dodge"  : 10,
	"skill_name" : "藏形匿迹"
]),
([	"action" : "$n身形拔地而起，使出一招“飞灵八方”，但见四面八方都是$n的身影，$N顿时茫然失措，攻势全失。\n",
	"dodge"  : 20,
	"skill_name" : "飞灵八方"
]),
([	"action" : "$n身形一纵，跃在半空，一招“隐景舞天”，在空中连翻几个跟斗，稳稳地落在$N身后\n",
	"dodge"  : 30,
	"skill_name" : "隐景舞天"
]),
([	"action" : "$n眼见敌招攻来，忽然一招“解行遁变”，身子往回轻轻一侧，刚好避开$N的猛攻。\n",
	"dodge"  : 40,
	"skill_name" : "解行遁变"
]),
([	"action" : "$n长啸一声，纵身一跃，一式“弃厄飞霄”，腾空飞起数丈，尽数避开$N的攻击\n",
	"dodge"  : 50,
	"skill_name" : "弃厄飞霄"
]),
([	"action" : "$n身形一闪，一式“回神转玄”，忽然转到$N身后，$N扑了一个空。\n",
	"dodge"  : 60,
	"skill_name" : "回神转玄"
]),
([	"action" : "$n身形晃动，使出一招“出有入无”，似左实右，忽前忽后，若有若无的闪过$N攻击。\n",
	"dodge"  : 70,
	"skill_name" : "出有入无"
]),
([	"action" : "$n身形飘然而起，使出一招“乘虚御空”，姿态飘逸，闪过$N攻击。\n",
	"dodge"  : 80,
	"skill_name" : "乘虚御空"
])
});

mapping query_action(object me, object weapon)
{
	int zhaoshu, level;

	zhaoshu = sizeof(action);
	level   = (int) me->query_skill("xuanmen-yinlun");

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
		return notify_fail("你的精力太差了，不能练玄门隐沦。\n");
	me->receive_damage("jingli", 30);
	return 1;
}
