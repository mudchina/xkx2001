// revive.c
// by Xuanyuan   7/2001
/*虚竹见了她的伤势，想起聪辩先生苏星河曾教过他这门治伤之法，当即催驼近前
，左手中指连弹，已封闭了那女子断臂处的穴道，血流立止。第六次弹指时，使的是
童姥所教的一招‘星丸跳掷’，一股的北冥真气射入她的臂根‘中府穴’中。那女子
“啊”的一声大叫，醒了转来，
*/

#include <ansi.h>

int exert(object me, object target)
{	
	if( !target )		
		return notify_fail("你自己是清醒的吗？\n");	

	if( me->is_fighting() || target->is_fighting())		
		return notify_fail("战斗中无法运功！\n");	

	if(target == me)		
		return notify_fail("你不能对自己运功！\n");	

	if( (int)me->query("max_neili") < 1000 )		
		return notify_fail("你的内力修为不够。\n");	

	if( (int)me->query("neili") < 350 )		
		return notify_fail("你的真气不够。\n");        

	if( living(target) )		
		return notify_fail( target->name() +"已经是清醒的！\n");	

	message_vision(HIY "$N左手中指连弹，一招‘星丸跳掷’，一股真气射入$n的臂根‘中府穴’中。\n\n" NOR,me, target );	

	target->revive(); 
    	
	me->add("neili", -250);	
	me->set("jiali", 0);                
	me->start_busy(2);                
	target->start_busy(2);	

	return 1;
}