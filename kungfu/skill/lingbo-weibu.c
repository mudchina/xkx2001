//Cracked by Roath
// lingbo-weibu.c 凌波微步
// AceP, Xuy

inherit SKILL;

mapping *action = ({
([	"action" : "但是$n左足跨出，既踏“中孚”，立转“既齐”，$N招式明明可以把$n围住，不\n知怎的，$n如鬼魅般的跨出圈外。\n",
	"dodge"  : 10
]),
([	"action" : "$n左足向东跨出，不料踏实之时，身子已在西北角上，尽管$N的招式迅如风雷，\n仍然尽数落空！\n",
	"dodge"  : 20
]),
([	"action" : "$n自管自地踏步，毫不理会$N的攻击，每一步都踏在别人想不到的地方，闪得几\n闪，竟到了$N的背后！\n",
	"dodge"  : 30
]),
([	"action" : "$n身形微晃，有若飘电，步法古怪之极，自“豫位”，上“观位”，匪夷所思的\n避开了$N的这一招。\n",
	"dodge"  : 40
]),
([	"action" : "$n足下一个踉跄，乘势向左斜出半步，既踏“中孚”，立转“井位”，不成章法，\n却在间不容发的空隙中避过了$N的招式。\n",
	"dodge"  : 50
]),
([	"action" : "$n侧身一让，踏“中孚”，转“盅位”，瞻之在前，忽焉在后，$N招数的落点与$n\n仅有厘毫之差，然而却总是差了这一星半点，无一命中。\n",
	"dodge"  : 60
]),
([	"action" : "$n竟然闭上双眼，如闲庭散步一般游走，在$N的招式圈中左上右落，东歪西斜。\n$N连$n的衣带也扫不到一片！\n",
	"dodge"  : 70
]),
([	"action" : "$n足不点地，飘然而走，东一幌、西一斜，便如游鱼一般，从$N招式的缝隙之中\n硬生生地挤了过去。\n",
	"dodge"  : 80
]),
([	"action" : "$n踉踉跄跄，连滚带爬，但每一步均踏在意想不到的位置上，险而又险地把$N的\n招式堪堪躲过。\n",
	"dodge"  : 90
]),
([	"action" : "$n面带微笑，身法虚无缥缈，御风而行，$N一招已至面前，却不料$n飘在半空顺势\n而出，当真逍遥似仙！\n",
	"dodge"  : 100
]),
});

mapping query_action(object me, object weapon)
{
	int zhaoshu, level;

	zhaoshu = sizeof(action);
	level   = (int) me->query_skill("lingbo-weibu");

	if (level < 120 )
		zhaoshu -= (119-level)/20;

	return action[random(zhaoshu)];
}

int valid_enable(string usage)
{
	return usage == "dodge";
}

int valid_learn(object me)
{
	return 1;
}

string query_dodge_msg(string limb)
{
// The following codes are buggy, because "me" is the attacker instead
// of defender.
/*	object me, ob;
	mapping action;

	me = this_player();
	action = query_action(me, ob);

	return action["action"];
*/
        return action[random(sizeof(action))]["action"];

}

int practice_skill(object me)
{
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力太低了，不能练凌波微步。\n");
	me->add("neili", -50);
	me->add("jingli", -50);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"lingbo-weibu/" + action;
}

