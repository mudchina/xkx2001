//Cracked by Roath
// perform.c

#include <ansi.h>
#include <login.h>

int update_condition(object me, string skill_type)
{
	if ( !me->is_fighting() )
		return 0;
	return 1;
}
