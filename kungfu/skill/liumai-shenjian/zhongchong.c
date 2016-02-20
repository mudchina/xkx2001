//Cracked by Roath
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;
int perform(object me, object target)
{
	int my_neili, op_neili, my_exp, op_exp;

	        if( !me->is_fighting() ) 
                return notify_fail("你必须在战斗中才能使用中冲剑法！\n");

        if( !target && me->is_fighting() ) target = offensive_target(me);

        if( !target || !target->is_character() || target->query("race") 
!= "人类" )
                return notify_fail("你要对谁用中冲剑法？\n");

        if( environment(target)->query("no_fight") )
                return notify_fail("你不能偷袭！\n");

        if( me->query("neili") <= 500 )
                return notify_fail("你的内力不足，无法使用中冲剑法！\n");

	if( (int)me->query_skill("liumai-shenjian", 1)< 130)
	return notify_fail("你在六脉神剑上的修为不够，无法使用中冲剑法！\n");
	
	my_neili = me->query("neili", 1);
	op_neili = target->query("neili", 1);
	my_exp   = me->query("combat_exp", 1);
	op_exp   = target->query("combat_exp", 1);

message_vision(HIR "$N双手连点，顿时无形剑气漫天！\n\n" NOR, me, target);

	me->add("neili", -300);
	if (my_exp>op_exp) {
		if (my_neili > op_neili) {
		me->add("neili", -(op_neili));
		if (my_neili<0){
		me->set("neili", 0);
		}
		message_vision(HIR 
"$n避无可避，只得双掌全力击出，与$N内力相博！\n\n" NOR, me, target);
		target->set("neili", 0);
tell_object(target, RED "你顿时觉得全身一阵虚脱，真气荡然全无！\n"NOR);
		me->start_busy(3);
		target->start_busy(2);
		}
	else {
	message_vision(HIR
	"$n避无可避，只得双掌全力击出，与$N内力相博！\n\n" NOR, me, target);
	me->set("neili",0);
	target->set("neili", (op_neili/2));
	tell_object(me, RED "你顿时觉得全身一阵虚脱，真气荡然全无！\n"NOR);
	tell_object(target,RED 
"你一掌击出，将$N的指力尽数荡散，只见$N脸色一阵惨白！\n"NOR);
	me->start_busy(2); 
        target->start_busy(2);
                }
	}
	else {
	message_vision(HIR "n连忙伏底，狼狈不堪的躲了开去！\n\n" NOR, 
me, target);   
	me->start_busy(1);
	return 1;
}
}

        

	        




