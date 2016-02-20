//Cracked by Roath
// /kungfu/condition/santa.c
// sdong, 12/24/98

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	object obj, *inv;
	int i, found;

	me->apply_condition("santa", duration - 1);

	if( duration < 1 )
	{
		return 0;
	}
	return CND_CONTINUE;
}


