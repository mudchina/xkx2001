//Cracked by Roath
// mo-bang.c  魔棒
// by ALN 2 / 98

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N姿式异常笨拙，手中$w直指$n的势头",
        "force" : 150,
        "dodge" : 30,
        "damage": 80,
        "lvl"   : 30,
        "post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        "damage_type" : "挫伤"
]),

([      "action": "$N沉肩滑步，手中$w飞舞罩住$n下盘各处",
        "force" : 200,
        "dodge":  30,
        "damage": 60,
        "lvl"   : 60,
        "post_action": (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :), 
        "damage_type" : "挫伤"
]),

([      "action": "$N一招「以拙御巧」，全身骤然缩成一团，所持棍棒指向$n各处要穴",
        "force" : 300,
        "dodge":  50,
        "damage": 80,
        "lvl"   : 90,
        "post_action": (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :), 
        "damage_type" : "挫伤"
]),

([      "action": "$N手中$w径自直点，与$n攻势联成了一条直线",
        "force" : 400,
        "dodge":  40,
        "damage": 60,
        "lvl"   : 120,
        "post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        "damage_type" : "挫伤"
]),
});

int valid_enable(string usage) { return usage == "stick" || usage == "parry"; }

int valid_learn(object me)
{
        return notify_fail("这不是你想学就能学的。\n");
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("mo-bang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        return notify_fail("这不是你想练就能练的。\n");
}

string perform_action_file(string action)
{
        return __DIR__"mo-bang/" + action;
}

/*
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        object v_weapon, my_weapon;
        int ap, dp;

        if( !objectp(v_weapon = victim->query_temp("weapon")) ) return;
        if( !objectp(my_weapon = me->query_temp("weapon")) ) return;
        if( my_weapon->query("skill_type") != "stick" ) return;

        ap = (int)me->query_skill("stick");
        ap += (int)me->query_temp("apply/attack");
        ap = ap * ap * ap;

        dp = (int)victim->query("combat_exp");

        if( random(ap + dp) > dp ) {
                message_vision(HIR"\n$N一副招架无方的挨打神态，然手中所持" + my_weapon->name() + "所处方位实是巧妙到了极处！！！\n"NOR, me);
                message_vision(HIR"$N别无它法，不得不抛弃手中" + v_weapon->name() + "，俯首屈膝，跪在$n面前。\n\n"NOR, victim, me);
                v_weapon->unequip();
                v_weapon->move(environment(victim));
                victim->start_busy(1 + random(2));
        }
}
*/     
