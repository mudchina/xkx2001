//Cracked by Roath

#include <login.h>

int update_condition(object me, int duration)
{
	if (duration < 1) return 0;
	me->apply_condition("cool_drug", duration - 1);
	return 1;
}
