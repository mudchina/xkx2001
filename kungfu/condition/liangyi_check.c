//Cracked by Roath
// A persistant check to prevent ppls from using hebi to gain extra power

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   if( !me->is_fighting() && me->query_temp( "hebi" ) ) {
	int amount = me->query_temp( "hebi_power" );

	me->add_temp("apply/attack", -amount);
        me->add_temp("apply/dodge", -amount);
        me->delete_temp("hebi");
        me->delete_temp("hebi_power");
	me->apply_condition("liangyi_check", 0);

	return 0;
   }
   else if( !me->query_temp( "hebi" ) ) {
	return 0;
   }
   else {		
   	return CND_CONTINUE;
   }	
}
