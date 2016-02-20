//Cracked by Roath
//kane

#include <login.h>

int update_condition(object me, int duration)
{
	if (duration < 1) return 0;
	me->apply_condition("hot_drug", duration - 1);
	if (duration == 1 && me->query_temp("yaopu/int")){
		me->add_temp("apply/intelligent", -10);
		me->delete_temp("yaopu/int");
	}
	return 1;
}
