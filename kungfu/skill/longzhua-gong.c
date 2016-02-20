//Cracked by Roath
// longzhua-gong.c -龙爪功
// maco 7/9

inherit SKILL;
#include <combat.h>
#include <ansi.h>

int next_hit(object me, object victim, object weapon, int damage);

mapping *action = ({
([      "action" : "$N双手齐出，自上而下同抓，使一招「抢珠式」，迅猛之至，直拿向$n左右太阳穴",
        "force" : 120,
        "dodge" : 5,
        "lvl"   : 0,
        "skill_name" : "抢珠式" ,
        "post_action": (: next_hit :),  
        "damage_type" : "内伤"
]),
([      "action" : "$N双手一个圈转，使招「捞月式」，右手倏忽而出，虚拿$n后脑“风府穴”",
        "force" : 130,
        "dodge" : 5,
        "damage": 5,
        "lvl"   : 6,
        "skill_name" : "捞月式" ,   
        "post_action": (: next_hit :),
        "damage_type" : "内伤"
]),
([      "action" : "$N使出一招「拿云式」，左手虚探，右手挟着一股劲风，直拿向$n左肩“缺盆穴”",
        "force" : 150,
        "dodge" : 10,
        "damage": 5,
        "lvl"   : 12,
        "skill_name" : "拿云式" ,       
        "post_action": (: next_hit :),  
        "damage_type" : "内伤"
]),
([      "action" : "$N使一招「捕风式」，左手五指朝$n的$l急抓而下，手法劲力稳迅兼备，势道凌厉之极",
        "force" : 180,
        "dodge" : 10,
        "damage": 10,
        "lvl"   : 18,
        "skill_name" : "捕风式" ,     
        "post_action": (: next_hit :),
        "damage_type" : "抓伤"
]),
([      "action" : "$N猛地纵身而起，一招「捉影式」向$n扑将下来，矫健迅捷，威势非凡",
        "force" : 220,
        "dodge" : 15,
        "damage": 10,
        "lvl"   : 24,
        "skill_name" : "捉影式" ,               
        "post_action": (: next_hit :),
        "damage_type" : "抓伤"
]),
([      "action" : "祗听呼地一响，$N右臂疾伸而出，五指微微上下颤动，一招「抚琴式」抓向$n的$l",
        "force" : 260,
        "dodge" : 15,
        "damage": 15,
        "lvl"   : 30,
        "skill_name" : "抚琴式" ,               
        "post_action": (: next_hit :),
        "damage_type" : "抓伤"
]),
([      "action" : "$N左手上拦，右手内挥，陡然化为一招「鼓瑟式」抓向$n$l，劲力威猛无俦",
        "force" : 300,
        "dodge" : 25,
        "damage": 20,
        "lvl"   : 45,
        "skill_name" : "鼓瑟式" ,               
        "post_action": (: next_hit :),
        "damage_type" : "抓伤"
]),
([      "action" : "$N双手「批亢式」疾攻而出，犹如龙影飞空，双爪急舞，瞬息之间，已将$n压制得无处躲闪",
        "force" : 350,
        "dodge" : 25,
        "damage": 25,
        "lvl"   : 50,
        "skill_name" : "批亢式" ,               
        "post_action": (: next_hit :),
        "damage_type" : "抓伤"
]),
([      "action" : "$N踏上几步，化做一招「掏虚式」，右手向$n$l抓将下来，这一抓自腕至指伸得笔直，劲道凌厉已极",
        "force" : 400,
        "dodge" : 30,
        "damage": 25,
        "lvl"   : 55,
        "skill_name" : "掏虚式" ,               
        "post_action": (: next_hit :),
        "damage_type" : "抓伤"
]),
([      "action" : "$N退後一步，架势似守实攻，大巧若拙，「抱残式」稳凝如山般使将出来",
        "force" : 460,
        "dodge" : 40,
        "damage": 30,
        "lvl"   : 60,
        "skill_name" : "抱残式" ,       
        "post_action": (: next_hit :),
        "damage_type" : "抓伤"
]),
([      "action" : "$N一改原先刚猛路子，化做「守缺式」，爪路刚猛中暗藏阴柔，实已到了返璞归真，炉火纯青的境界",
        "force" : 520,
        "dodge" : 40,
        "damage": 50,
        "lvl"   : 70,
        "skill_name" : "守缺式" ,
        "post_action": (: next_hit :),
        "damage_type" : "内伤"
])
});

int valid_enable(string usage) { return usage=="claw" ||  usage=="parry"; }

int valid_combine(string combo) { return combo=="qianye-shou"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练龙爪功必须空手。\n");
        if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
                return notify_fail("你的混元一气功火候不够，无法学龙爪功。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练龙爪功。\n");
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action); i > 0; i--)
                if(level >= action[i-1]["lvl"])
                        return action[i-1]["skill_name"];
}


mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("longzhua-gong",1);

        if( me->query_temp("lzg_lianhuan"))
        {
	return action[me->query_temp("lzg_lianhuan")-1];
        }

		else {
	for(i = sizeof(action); i > 0; i--) 

	if(level > action[i-1]["lvl"])
                return action[NewRandom(i, 20, level/5)];
	}
}


int practice_skill(object me)
{
        if ((int)me->query("jingli") < 30)
                return notify_fail("你的精力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练龙爪功。\n");

        if( (int)me->query_skill("banruo-zhang", 1) < 180 )
                return notify_fail("你的般若掌修为还不够。\n");

        me->receive_damage("jingli", 30);
        me->add("neili", -10);
        return 1;
}

int next_hit(object me, object victim, object weapon, int damage)
{
        string *msg;
        msg = ({
                HIR"\n$N一抓不中，次抓随至，来势更加迅捷刚猛！" NOR,
                HIR"\n$N龙爪手源源而出，一招落空，又即连续急攻！" NOR,
                HIR"\n$n才躲过这招，$N次招又至，抓法快极狠极！"NOR,
        });

        if(damage==RESULT_DODGE 
        && (int)me->query_skill("longzhua-gong",1) > 100 
        && 2>random(3)
        && !me->query_temp("lzg_lianhuan")
        && !me->query_temp("next_hit")) {
        message_vision(msg[random(sizeof(msg))] , me,victim );
        me->add("neili", -20);
        me->add_temp("next_hit",1);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
        me->delete_temp("next_hit");
        }
        
}

string perform_action_file(string action)
{
                return __DIR__"longzhua-gong/" + action;
}
