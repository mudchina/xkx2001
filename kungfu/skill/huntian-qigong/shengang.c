//Cracked by Roath
//shengang.c 混天神罡

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

private int remove_effect(object me, object weapon);

int exert(object me, object target)
{
        object weapon;
        int skill, skill1;

        if( me->query_temp("shengang") )
                return notify_fail("你已在使用混天神罡了！\n");

        if( !objectp(weapon = me->query_temp("weapon") ) )
                return notify_fail("你未持武器，如何能够以混天神罡附注真力？\n");

        if ( weapon->query("weapon_prop/damage") > 50 )         
                return notify_fail(weapon->query("name") +"的锋刃已到极限，混天神罡难以再提高其威力。\n");

        if( me->query_skill("force") < 150 )
                return notify_fail("你的混天气功火候未到，无法施展混天神罡！\n");

        if( me->query("neili") <= 800 )
                return notify_fail("你的内力不够施展混天神罡！\n");
        if( me->query("jingli") <= 200 )
                return notify_fail("你的精力不够施展混天神罡！\n");

        skill = me->query_skill("force");
        skill1 = skill;

        message_vision(HIR "\n$N凝神默然运功，不一会手上的$n似乎发出淡淡光辉！\n" NOR, me, weapon);

        me->set_temp("shengang", 1);

        weapon->set("no_get", "这样东西不能离开那儿。\n");
        weapon->set("no_drop","这样东西不能离开你。\n");
        weapon->unequip();

        if ( weapon->query("rigidity") < 100 ) {
                weapon->add("rigidity", 300+skill);
                weapon->set_temp("shengang", 1);
        }
        else if ( weapon->query("rigidity") < 500 ) {
                weapon->add("rigidity", 200+skill);
                weapon->set_temp("shengang", 2);
        }
        else if ( weapon->query("rigidity") < 1000 ) {
                weapon->add("rigidity", 100+skill);
                weapon->set_temp("shengang", 3);
        }
        else {
                weapon->add("rigidity", 50+skill);
                weapon->set_temp("shengang", 4);
        }

        if ( skill1 > 150 ) {
                skill1 = 150;
        }
        if ( skill1 > weapon->query("weapon_prop/damage"))
                skill1 = weapon->query("weapon_prop/damage");

        weapon->add("weapon_prop/damage", skill1/2);
        weapon->set_temp("rig", skill);
        weapon->set_temp("dam", skill1);

        call_out("checking", 1, me, weapon);
        me->add("neili", -skill*3/2);
        me->add("jingli", -skill/3);
        weapon->wield();

        return 1;
}

void checking(object me, object weapon)
{
        if ( me->query_temp("shengang") < (int)me->query_skill("force")/8 ) {
           if ( environment(weapon) != me || weapon != me->query_temp("weapon") ) {
                remove_effect(me, weapon);
                tell_object(me, HIR "\n你放弃手中的"+weapon->name()+"，缓然收起混天气功将内力纳回丹田。\n\n" NOR);
                return;
           }
           else if ( weapon->query("weapon_prop") == 0 ) {
                remove_effect(me, weapon);
                tell_object(me, HIR "\n你的"+weapon->name()+"已毁，无奈收起混天气功将内力纳回丹田。\n\n" NOR);
                return;
           }
           else if ( me->query_skill_mapped("force") != "huntian-qigong" ) {
                remove_effect(me, weapon);
                tell_object(me, HIR "\n你中途改用其他内功心法，无法再施展混天神罡！\n\n" NOR);
                return;
           }

           me->add_temp("shengang", 1);
           call_out("checking", 1, me, weapon);
        }
        else {
           remove_effect(me, weapon);
           message_vision(HIR "\n$N的混天气功运行完毕，将内力收回丹田，$n上的淡光亦消失无踪。\n\n" NOR, me, weapon);
        }
}       

private int remove_effect(object me, object weapon)
{
        int amount, amount1;
        
        amount = weapon->query_temp("rig");
        amount1 = weapon->query_temp("dam");
        
        if ( weapon == me->query_temp("weapon") ) {
                weapon->unequip();
                me->set_temp("equip_weapon", 1);
        }
        
        weapon->add("weapon_prop/damage", -amount1/2 );
        
        if ( weapon->query_temp("shengang") == 1 ) {
                weapon->add("rigidity", -(300+amount));
        }
        else if ( weapon->query_temp("shengang") == 2 ) {
                weapon->add("rigidity", -(200+amount));
        }
        else if ( weapon->query_temp("shengang") == 3 ) {
                weapon->add("rigidity", -(100+amount));
        }
        else {
                weapon->add("rigidity", -(50+amount));
        }

        weapon->delete_temp("shengang");
        weapon->delete_temp("rig");
        weapon->delete_temp("dam");
        weapon->delete("no_drop");
        weapon->delete("no_get");

        if ( me->query_temp("equip_weapon") ) {
                weapon->wield();
                me->delete_temp("equip_weapon");
        }
        
        me->delete_temp("shengang");
        
        return 1;
}
