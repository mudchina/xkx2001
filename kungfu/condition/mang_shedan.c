//Cracked by Roath
//Ryu

#include <login.h>

int update_condition(object me, int duration)
{
	if (duration < 1) return 0;
	me->apply_condition("mang_shedan", duration - 1);
	if (duration == 1 && me->query_temp("dan_effect")){
	me->add_temp("apply/strength", -1);
        me->add_temp("apply/constitution", -1);
	me->delete_temp("dan_effect");
	return 1; 
	}
	return 1;
}
