//Cracked by Roath
//feizhang.c  天山飞杖

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

void check_fight(object me, object target, object weapon);
private int remove_attack(object me, object weapon);

int perform(object me, object target)
{
        object weapon;
        int skill,skill2,damage;
        string *limbs, limb, result, str, type;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("天山飞杖只能对战斗中的对手使用。\n");

        weapon = me->query_temp("weapon");
        if( !objectp(weapon) || weapon->query("skill_type") != "staff" )
                return notify_fail("你手中无杖，如何能够施展天山飞杖？\n");

        if( me->query_skill_mapped("force") != "huagong-dafa" )
                return notify_fail("你所用的并非化功大法，无法施展天山飞杖！\n");

        if( me->query_skill("force") < 140 )
                return notify_fail("你的化功大法火候未到，无法配合杖法施展疯魔飞杖！\n");

        if( me->query_skill("tianshan-zhang", 1) < 140 )
                return notify_fail("你天山杖法修为不足，还不会使用天山飞杖！\n");

        if( me->query("neili") <= 1000 )
                return notify_fail("你的内力不够施展天山飞杖！\n");
        if( me->query("jingli") <= 500 )
                return notify_fail("你的精力不够施展天山飞杖！\n");

        skill = me->query_skill("staff");
	skill2 = target->query_skill("parry");
        
        message_vision(HIW "\n$N深深吸了口气，一声狂呼， 将手中的"+weapon->name()+"向$n掷出！\n\n" NOR, me, target);

        me->add("neili", -500);
        me->add("jingli", -300);
        weapon->unequip();
        if ( random(me->query("combat_exp")/1000*skill) > random(target->query("combat_exp")/1000*skill2) ) {

		limbs = target->query("limbs");
        	limb = limbs[random(sizeof(limbs))];
	        type = "挫伤";

           	message_vision(HIR+weapon->name()+"加着一阵狂风猛得撞在$n"+limb+"上！\n" NOR, target, weapon);

		damage=(skill+me->query("huagong-dafa"))*3;
		target->add("qi",-damage);
	        target->receive_damage("qi", random(damage), me);

        	result = COMBAT_D->damage_msg(damage, type);
	        result = replace_string( result, "$l", limb);

        	str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
		target->start_busy(random(3)+1);
	        message_vision(result, me, target);
        	message_vision("($N"+str+")\n", target);

	} else {
                message_vision(HIY "$N看得分明，急忙向旁边一跃，闪开了"+weapon->name()+"的攻击\n" NOR, target);
        }
        me->start_busy(random(3)+1);
	message_vision(HIB+weapon->name()+"撞到山石上，断成了无数截。\n"NOR);
        weapon->move("/u/wsky/xiaoyao");
        return 1;
}

