//Cracked by Roath
//yunwu.c 百变千幻衡山云雾十三式 by maco

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int skill;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「百变千幻衡山云雾十三式」只能对战斗中的对手使用。\n");

        if( me->query_temp("yunwu") )
                return notify_fail("你已经使出「百变千幻衡山云雾十三式」了！\n");

        weapon = me->query_temp("weapon");
        if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
                return notify_fail("你手中无剑，如何能施展「百变千幻衡山云雾十三式」？\n");

        if( me->query_skill("dodge") < 100 )
                return notify_fail("你的轻功修为未到，难以施展「百变千幻衡山云雾十三式」的变幻之处！\n");

        if( me->query_skill("sword") < 100 )
                return notify_fail("你在剑法上的造诣不足以使出「百变千幻衡山云雾十三式」！\n");

        if( me->query("neili") <= 200 )
                return notify_fail("你的内力不够施展「百变千幻衡山云雾十三式」！\n");

        skill = me->query_skill("sword");

	if(random(target->query_skill("parry"))>skill) {
        message_vision(HIW "\n$N意欲使出「百变千幻衡山云雾十三式」，但是$n严加戒备，全身门户，无不守备綦谨，难以奏效！\n" NOR, me, target);
	me->start_busy(2);

	}
	else{
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        message_vision(HIC "\n但见寒光陡闪，$N手中"+weapon->query("name")+HIC"越使越快，如梦如幻，正是衡山派绝技"+HIW"「百变千幻衡山云雾十三式」"NOR+HIC"！\n" NOR, me, target);

        me->set_temp("yunwu", 1);
        call_out("checking", 1, me, target);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), skill/4);
	}
        me->add("neili", -200);
        me->add("jingli", -100);
        return 1;
}


void checking(object me, object target)
{

	object weapon;
	weapon = me->query_temp("weapon");

        if ( me->query_temp("yunwu")  ) {
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword") {
                tell_object(me, "\n你手中没有持剑，「百变千幻衡山云雾十三式」的攻势便即瓦解！\n" NOR);
		me->delete_temp("yunwu");
                return;
           }


           else if ( weapon->query("weapon_prop") == 0 ) {
                tell_object(me, "\n你的"+weapon->name()+"已毁，无法持续「百变千幻衡山云雾十三式」的攻势！\n\n" NOR);
		me->delete_temp("yunwu");
                return;
           }
           else if ( (int)me->query("neili") < 400  ) {
                tell_object(me, "\n你的内力后继不足，难以持续「百变千幻衡山云雾十三式」的威力，好收缓剑招。\n\n" NOR);
		me->delete_temp("yunwu");
                return;
           }
           else if ( me->query_skill_mapped("sword") != "luoyan-jian" ) {
                tell_object(me, "\n你转而施展其他剑法，无法再以「百变千幻衡山云雾十三式」攻敌！\n\n" NOR);
		me->delete_temp("yunwu");
                return;
           }
           else if (!me->is_fighting()) {
                tell_object(me,  "\n你现在没有和人过招，当下收回了「百变千幻衡山云雾十三式」的攻势。\n\n" NOR);
		me->delete_temp("yunwu");
                return;
           }
	   else call_out("checking", 1, me, target);
	}
	   else return;

}  

void remove_effect(object me, int amount)
{

        if ( me->query_temp("yunwu") ) {
                message_vision(HIW"\n$N剑招渐缓，已将一套「百变千幻衡山云雾十三式」使完！\n" NOR, me);
        me->delete_temp("yunwu");
        }
}
