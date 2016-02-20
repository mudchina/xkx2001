//Cracked by Roath
// damo-jian.c 达摩剑

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([	"action":"$N使一式「万事随缘往」，手中$w嗡嗡微振，幻成一条疾光刺向$n的$l",
	"force" : 120,
        "dodge" : -10,
	"damage": 55,
	"lvl" : 0,
	"skill_name" : "万事随缘往",
	"damage_type":	"刺伤"
]),
([	"action":"$N错步上前，使出「来去若梦行」，剑意若有若无，$w淡淡地向$n的$l挥去",
	"force" : 140,
        "dodge" : -10,
	"damage": 60,
	"lvl" : 9,
	"skill_name" : "来去若梦行",
	"damage_type":	"割伤"
]),
([	"action":"$N一式「浮世沧桑远」，纵身飘开数尺，运发剑气，手中$w遥摇指向$n的$l",
	"force" : 160,
        "dodge" : 5,
	"damage": 65,
	"lvl" : 18,
	"skill_name" : "浮世沧桑远",
	"damage_type":	"割伤"
]),
([	"action":"$N纵身轻轻跃起，一式「轮回法舟轻」，剑光如轮疾转，霍霍斩向$n的$l",
	"force" : 180,
        "dodge" : 10,
	"damage": 70,
	"lvl" : 27,
	"skill_name" : "轮回法舟轻",
	"damage_type":	"割伤"
]),
([	"action":"$N手中$w中宫直进，一式「水月通禅寂」，无声无息地对准$n的$l刺出一剑",
	"force" : 220,
        "dodge" : 15,
	"damage": 75,
	"lvl" : 36,
	"skill_name" : "水月通禅寂",
	"damage_type":	"刺伤"
]),
([	"action":"$N手中$w斜指苍天，剑芒吞吐，一式「鱼龙听梵音」，对准$n的$l斜斜击出",
	"force" : 260,
        "dodge" : 5,
	"damage": 80,
	"lvl" : 44,
	"skill_name" : "鱼龙听梵音",
	"damage_type":	"刺伤"
]),
([	"action":"$N左指凌空虚点，右手$w逼出丈许雪亮剑芒，一式「千里一苇去」刺向$n的$l",
	"force" : 320,
        "dodge" : 5,
	"damage": 85,
	"lvl" : 52,
	"skill_name" : "千里一苇去",
	"damage_type":	"刺伤"
]),
([	"action":"$N合掌跌坐，一式「禅心顿自明」，$w自怀中跃出，如疾电般射向$n的胸口",
	"force" : 380,
        "dodge" : 5,
	"damage": 90,
	"lvl" : 60,
	"skill_name" : "禅心顿自明",
	"damage_type":	"刺伤"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_combine(string combo) { return combo=="xiuluo-dao"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
		return notify_fail("你的混元一气功火候太浅。\n");
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
        int i, j, wt, level;
       	object target;
	string *msg;

	level   = (int) me->query_skill("damo-jian",1);
	wt = me->query_temp("sl_weituo");
	target = me->select_opponent();
	weapon = me->query_temp("weapon");

	msg = ({ 
		HIR"\n$N剑招越攻越急，出剑突快，顷刻之间，$n" +HIR"上全是进手招数。\n"NOR,
		HIY"\n$N身随剑转，回剑横掠，一剑跟著一剑，绵绵不尽，剑招连环进击，紧密无比。\n"NOR,
		HIC"\n原本达摩剑走的均是刚猛路子，此刻却带了三分灵动之气，剑势更加厉害！\n"NOR,
		HIW"\n这时$N心剑合一，势成自然，将「韦陀伏魔剑」发挥到了淋漓尽致。\n"NOR,
	});

	if( wt > 1 && wt < 6 && !me->query_temp("weituo_attack")) {

		message_vision( msg[wt-2] , me, weapon);
		me->set_temp("weituo_attack", 1);
		for( j=0; j < wt-1; j++ )
		{
			me->add("neili", -50);
			COMBAT_D->do_attack(me, target, weapon);
		}
		me->delete_temp("weituo_attack", 1);
		me->add_temp("sl_weituo", 1);

	}

        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("jingli") < 50)
		return notify_fail("你的精力不够练达摩剑。\n");

        if( (int)me->query_skill("qianye-shou", 1) < 100 )
                return notify_fail("你的如来千叶手修为还不够。\n");

	me->receive_damage("jingli", 25);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"damo-jian/" + action;
}
