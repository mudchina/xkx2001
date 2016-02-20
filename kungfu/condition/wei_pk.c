//Cracked by Roath
// wei_pk.c

#include <login.h>

int update_condition(object me, int duration)
{
	if (duration < 2) 
	{
		me->delete_temp("blood_sucked");
		return 0;
	}
	me->apply_condition("wei_pk", duration - 1);
	return 1;
}
