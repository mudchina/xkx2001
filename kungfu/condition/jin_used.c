//Cracked by Roath
#include <login.h>

int update_condition(object me, int duration)
{
        if( duration < 1 )
	{
		me->delete_temp("medication/vulnerary");
		return 0;
	}
        me->apply_condition("jin_used", duration - 1);
        return 1;
}
