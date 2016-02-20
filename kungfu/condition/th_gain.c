//Cracked by Roath
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   me->apply_condition("th_gain", duration - 1);
   if( duration < 1 ) {
	me->delete_temp("exp_gain");
	me->delete_temp("pot_gain");
	return 0;
   }
   if(me->query_temp("exp_gain") > 1) me->add_temp("exp_gain", -2);
   if(me->query_temp("pot_gain") > 1) me->add_temp("pot_gain", -2);
   return CND_CONTINUE;
} 
