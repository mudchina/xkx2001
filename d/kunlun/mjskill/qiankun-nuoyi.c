//Cracked by Roath
// qiankun-nuoyi.c 乾坤大挪移
// by tony 97/7

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : YEL"$n滑如游鱼，在间不容发之际避开。\n"NOR,
        "dodge"  : 35
]),
([      "action" : YEL"但见$n四下转动，越奔越快，如风如火，似雷似电，足不点地的凌空飞行一般。\n"NOR,
        "dodge"  : 55
]),
([      "action" : YEL"$n施展挪移乾坤心法，一声清啸，拔身而起，在半空中轻轻一个转折，飘然落在丈许之外。\n"NOR,
        "dodge"  : 75
]),
([      "action" : YEL"陡然间$n身形拔起，在空中急速盘旋，连转四个圈子，愈转愈高，又是一个转折，轻轻巧巧得落在数丈之外。\n"NOR,
        "dodge"  : 100
])
});

string *parry_msg = ({
          YEL"那知$n跟著微转，一股柔和的劲力送出，将$N击向$n的$l的一招直荡了开去。\n"NOR,
          YEL"$n挪移乾坤，从中牵引，$N这招在中途转了方向，使了个空。\n"NOR,
          YEL"$n右手五指犹如抚琴鼓瑟，忽挑忽捻，忽弹忽拔，上身半点不动，片刻间将$N的这招力道尽数卸了。\n"NOR,
          YEL"却见$N这一招将要及$n，$n右手五指轻拂，$N招数竟然转向，从$n身侧斜了过去，相距虽不过三寸，这一招终于全然使了个空。\n"NOR,
          YEL"$n动也不动，待$N这招使到，内力斜引，将$N的力道挪移卸了开去。$N只觉犹似入了水中，更无半点着力处。\n"NOR,
});


int valid_enable(string usage)
{
        return (usage == "parry") || (usage == "dodge") || (usage == "finger");
}

int valid_combine(string combo) { return 1; }

string query_dodge_msg(string limb)
{
        object me;
	  int level, i;
 
        me = this_player();
	  level = me->query_skill("qiankun-nuoyi", 1) / 20;
	  if (level > sizeof(action))
		level = sizeof(action);

        return action[random(level)]["action"];
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

string query_parry_msg(object weapon)
{
        return parry_msg[random(sizeof(parry_msg))];
}

int valid_learn(object me)
{
        return notify_fail("乾坤大挪移只能通过研习《乾坤大挪移心法》和自己练习来提高。\n");
}

int practice_skill(object me)
{
        int jing_cost, jingli_cost, neili_cost, neili_want;
        int qlvl = me->query_skill("qiankun-danuoyi", 1);
        int jlvl = me->query_skill("jiuyang-shengong", 1);
        if ( qlvl < 140 )
            return notify_fail("你必须先研习《乾坤大挪移心法》，并获得乾坤大挪移第七层功力后，方能再通过练习提高。\n");
        if (me->query_skill("force", 1) < 180)
            return notify_fail("你的基本内功火侯还不够，练不了乾坤大挪移。\n");
        neili_want = qlvl / 20 * 300 * 2 / (1 + jlvl / 100);
        if ( (int)me->query("max_neili") < neili_want )
            return notify_fail("你的内力不够雄厚，练不了乾坤大挪移。\n");
        if ( (int)me->query("jingli") < 200 || (int)me->query("jing") < 200 || (int)me->query("neili") < 500 )
            return notify_fail("你的体力太差了，先歇息一会儿。\n");
        if ( jlvl < 100 ) jing_cost = 36000 / me->query_skill("force", 1);
        else jing_cost= 10000 / jlvl;
        jing_cost = jing_cost * qlvl / 100;
        neili_cost = jing_cost;
        jingli_cost = jing_cost;
        jing_cost = jing_cost * 20 / me->query("int");
        jingli_cost = jingli_cost * 20 / me->query("dex");
        neili_cost = neili_cost * 20 / me->query("con") / 2;
        me->receive_damage("jing", jing_cost);
        me->receive_damage("jingli", jingli_cost);
        me->add("neili", -neili_cost);
        return 1;
}
string perform_action_file(string action)
{
	return __DIR__"qiankun-nuoyi/" + action;
}
