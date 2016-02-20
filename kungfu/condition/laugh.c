//Cracked by Roath
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int neili, poison;

	if( !living(me) ) {
     		message_vision(HIY"$N身体一阵颤抖，睡梦中发出沉沉地笑生。\n", environment(me), me);
   	}
   	else {
   		     		
  		message_vision(HIY"$N突然间哈哈的大笑起来，脸上却露出痛苦的神色。\n",environment(me), me);	                    		   	
   	        
   	}
   	   	
   	me->start_busy(3);
   	
   	me->apply_condition("laugh", duration - random(5));
	
	
	if (me->query("combat_exp")>100000)
		me->add("jing", -25);		

   	if( duration < 1 ) {
   		message_vision(HIG"$N运了运气，发现体内的寒毒已经荡然无存。"NOR,me);	
   		return 0;
   	}
   	
   return CND_CONTINUE;
}
