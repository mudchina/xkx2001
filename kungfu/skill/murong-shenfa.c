//Cracked by Roath
// murong-shenfa.c 

#include <ansi.h>
#include <combat.h>

inherit SKILL;

mapping *action = ({
([      "action" : "$n身形略动，从$N的攻击范围中飘身出去，躲开了$N的攻击。\n",
        "dodge"  : 10
]),
([      "action" : "$n一个移形换位，$N顿时失去了攻击目标！\n",
        "dodge"  : 20
]),
([      "action" : "$n面带笑容，身形潇洒之极，堪堪避过$N的招式！\n",
        "dodge"  : 30
]),
([      "action" : "$n左手一个虚招，身子陡然间退后三尺，使$N的攻击尽数落在空处。\n",
        "dodge"  : 40
]),
([      "action" : "可是$n三晃二晃已经失去了踪迹。\n",
        "dodge"  : 50
]),
([      "action" : "$n身子右转，侧身避过$N的雷霆一击。\n",
        "dodge"  : 60
]),
([      "action" : "$n脚下一动，$N连$n的衣角也没有碰到半点！\n",
        "dodge"  : 70
]),
([      "action" : "$n展开慕容身法，当真飘然若仙，$N一时竟无计可施。\n",
        "dodge"  : 80
]),
([      "action" : "可是$n避了开去。\n",
        "dodge"  : 90
]),
([      "action" : "$n身形不动，运起内功，硬生生将肌肉吸入数寸，正好避开$N的攻击！\n",
        "dodge"  : 100
]),
});

mapping query_action(object me, object weapon)
{
        int zhaoshu, level;

        zhaoshu = sizeof(action);
        level   = (int) me->query_skill("murong-shenfa");

        if (level < 120 )
                zhaoshu -= (119-level)/20;

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
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力太低了，不能练慕容身法。\n");
        me->add("neili", -15);
        me->add("jingli", 25);
        return 1;
}

int is_special()
{
        return 1;
}

mixed hit_by(object me, object victim, int damage)
{
        int ap, dp, level;
        object weapon = me->query_temp("weapon");
        mapping prepare;
        string result, attack_skill;

        if ( victim->query_skill("murong-shenfa", 1) < 120
        || victim->query_skill_mapped("force") != "douzhuan-xingyi" 
        || victim->query_skill("douzhuan-xingyi", 1) < 120 
        || !living(victim) )
                return damage;

        dp = COMBAT_D->skill_power(victim, "dodge", SKILL_USAGE_DEFENSE);
        if( victim->query_skill_mapped("parry") == "canhe-zhi" )
                dp += COMBAT_D->skill_power(victim, "parry", SKILL_USAGE_DEFENSE);

        ap = COMBAT_D->skill_power(me, "dodge", SKILL_USAGE_DEFENSE);
        prepare = me->query_skill_prepare();
        if( !prepare ) prepare = ([]);

        if( objectp(weapon) ) attack_skill = weapon->query("skill_type");
        else switch( sizeof(prepare) )
        {
                case 0: attack_skill = "unarmed"; break;
                case 1: attack_skill = (keys(prepare))[0]; break;
                case 2: attack_skill = (keys(prepare))[me->query_temp("action_flag")]; break;
        }

        ap += COMBAT_D->skill_power(me, attack_skill, SKILL_USAGE_ATTACK);

        ap /= 100;
        dp /= 100;

        if ( random(ap+dp) > ap ) {
                result = HIW "$n脚下微微一动，$N连$n的衣角也未沾到半分！\n";
                result += "$n如逍遥神仙般好整以暇地向$N攻去。\n" NOR;
                me->start_busy( (int)victim->query_skill("murong-shenfa", 1)/50 );
                victim->add("neili", -20);
                victim->add("jingli", -20);
                damage = 0;

                return ([ "result" : result, "damage" : damage ]);
        }
        else if ( random(ap+dp) > ap ) {
                result = HIG "$n面带笑容，姿态潇洒地避到一旁，$N胸前大露破绽！\n";
                result += "$n抓住稍纵即逝的机会，立刻对$N发动攻势。\n" NOR;
                COMBAT_D->do_attack(victim, me, victim->query_temp("weapon"));
                victim->add("neili", -10);
                victim->add("jingli", -20);
                damage = 0;

                return ([ "result" : result, "damage" : damage ]);
        }
        else if ( random(ap+2*dp) > ap ) {
                result = HIY "$n身形飘然若仙，已然从从容容地避开了$N的攻击。\n" NOR;
                victim->add("jingli", -20);
                damage = 0;

                return ([ "result" : result, "damage" : damage ]);
        }
        else if ( random(ap+3*dp) > ap ) {
                result = HIM "$n身体陡然间向后飘出三尺，$N的招式尽数落空。\n" NOR;
                victim->add("jingli", -10);
                damage /= 5;
        
                return ([ "result" : result, "damage" : damage ]);
        }
        else 
                return damage;
}

