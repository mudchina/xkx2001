//Cracked by Roath
// mo.c 魔棒的「魔」字诀

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        object weapon, t_weapon;
        int ap, dp;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「魔」字诀只能对战斗中的对手使用。\n");

        weapon = me->query_temp("weapon");

        if( weapon->query("skill_type") != "stick" )
                return notify_fail("你手中无棒，如何使得魔棒的「魔」字诀？！\n");

        if( me->query("neili") <= 300 )
                return notify_fail("你的内力不够！\n");

        if( me->query("jingli") <= 200 )
                return notify_fail("你的精力不够！\n");

        if( (int)me->query_skill("stick") < 200 )
                return notify_fail("你的魔棒不够娴熟，不会使用「魔」字诀。\n");

        if( !objectp(t_weapon = target->query_temp("weapon")) )
                return notify_fail("魔棒的「魔」字诀，对没有握武器的对手无效。\n");

        message_vision(HIR"\n$N一副招架无方的挨打神态，然手中所持" + weapon->name() + "所处方位实是巧妙到了极处！！！\n"NOR, me);

        me->add("neili", -80);
        me->add("jingli", -20);

        ap = (int)me->query_skill("stick");
        ap += (int)me->query_temp("apply/attack");
        ap = ap * ap * ap / 3 + (int)me->query("combat_exp");

        dp = (int)target->query("combat_exp");

        if( random(ap + dp) > dp ) {
                message_vision(HIR"$N别无它法，不得不抛弃手中" + t_weapon->name() + "，俯首屈膝，跪在$n面前。\n\n"NOR, target, me);
                if( base_name(target) == "/kungfu/skill/yanxing-dao/copy/user" )
                        destruct(t_weapon);
                else {
                        t_weapon->unequip();
                        t_weapon->move(environment(target));
                }
                target->start_busy(1 + random(2));
        } else {
                message_vision(HIG"$N看破了$n的企图，并没有上当。\n\n"NOR, target, me);
                me->start_busy(1);
        }

        return 1;
}

