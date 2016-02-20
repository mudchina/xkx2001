//Cracked by Roath
// huashan-shenfa.c 华山身法
// qfy July 8, 1996

#include <ansi.h>
#include <combat.h>

inherit SKILL;

mapping *action = ({
([      "action" : "$n两臂鹏举，纵上丈余，一式「巨鹏亮翅」顿时避开了$N的凌厉攻势。\n",
        "dodge"  : 10
]),
([      "action" : "$n身随风飘，侧身向后倒纵，轻巧地一式「风送紫霞」，化解了$N的攻势。\n",
        "dodge"  : 20
]),
([      "action" : "$n一式「燕徊朝阳」，长袖飘飘身形晃动，一转眼间便绕到了$N的身后。\n",
        "dodge"  : 30
]),
([      "action" : "$n低头恭身，抱拳一式「却别苍松」，身子向后滑出，将$N的攻势化于无形。\n",
        "dodge"  : 40
]),
([      "action" : "$n使出「旭日初升」，笔直跃起，在半空中化为「金雁横空」，飘落到一旁。\n",
        "dodge"  : 50
]),
([      "action" : "$n一招「晚月朗星」，身形左右急速晃动，幻出数个身影，从容地破解$N的攻势。\n",
        "dodge"  : 60
]),
([      "action" : "$n含笑飘身使出「幻眼云湮」，身形幻成一道白影，轻飘飘地闪到$N的左侧。\n",
        "dodge"  : 70
]),
([      "action" : "$n凝气守中一招「苍龙盘岭」，身化长龙绕着$N急转，使其无从下手，攻势不攻自破。\n",
        "dodge"  : 80
])
});

mapping query_action(object me, object weapon)
{
        int zhaoshu, level;

        zhaoshu = sizeof(action);
        level   = (int) me->query_skill("huashan-shenfa");

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
// The following codes are buggy, because "me" is the attacker instead
// of defender.
/*
        object me, ob;
        mapping action;

        me = this_player();
        action = query_action(me, ob);

        return action["action"];
*/
        return action[random(sizeof(action))]["action"];

}

int practice_skill(object me)
{
        if( (int)me->query("jingli") < 40 )
                return notify_fail("你的精力太差了，不能练华山身法。\n");
        me->receive_damage("jingli", 30, "精力透支过度死了");
        return 1;
}


	/*  // remove special dodge // maco
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

        if ( victim->query_skill("huashan-shenfa", 1) < 120
        || victim->query_skill_mapped("force") != "zixia-gong" 
        || victim->query_skill("zixia-gong", 1) < 120 
        || !living(victim) )
                return damage;

        dp = COMBAT_D->skill_power(victim, "dodge", SKILL_USAGE_DEFENSE);
        if( victim->query_skill_mapped("parry") == "dugu-jiujian" )
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
                result = HIR "$n身形巧妙一晃闪过一边，$N劲招失手，一时有点手忙脚乱！\n";
                result += "$n捉紧时机，立刻对$N发动攻势！\n" NOR;
                me->start_busy( (int)victim->query_skill("huashan-shenfa", 1)/50 );
                victim->add("neili", -20);
                victim->add("jingli", -20);
                damage = 0;

                return ([ "result" : result, "damage" : damage ]);
        }
        else if ( random(ap+dp) > ap ) {
                result = HIR "$n身形巧妙一晃闪过一边，$N一招失手，攻守之势已露破绽！\n";
                result += "$n捉紧时机，立刻对$N发动攻势！\n" NOR;
                COMBAT_D->do_attack(victim, me, victim->query_temp("weapon"));
                victim->add("neili", -10);
                victim->add("jingli", -20);
                damage = 0;

                return ([ "result" : result, "damage" : damage ]);
        }
        else if ( random(ap+2*dp) > ap ) {
                result = HIR "$n身形巧妙一晃闪过一边，已然毫发无损地避开了$N的攻击。\n" NOR;
                victim->add("jingli", -20);
                damage = 0;

                return ([ "result" : result, "damage" : damage ]);
        }
        else if ( random(ap+3*dp) > ap ) {
                result = HIR "$n身形巧妙一晃闪过一边，将$N的力道卸去大半。\n" NOR;
                victim->add("jingli", -10);
                damage /= 5;
        
                return ([ "result" : result, "damage" : damage ]);
        }
        else 
                return damage;
}
	*/
