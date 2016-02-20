//Cracked by Roath
// /kungfu/condition/blind.c
// sdong, 12/12/98

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
void let_know(object me);

int update_condition(object me, int duration)
{
   object obj, *inv;
   int i, found;

	me->apply_condition("blind", duration - 1);

	if( duration < 2 )
	{
		call_out("let_know",1,me);
		return 0;
	}
	return CND_CONTINUE;
}

void let_know(object me)
{
        int amount = me->query_temp( "cimu_power" );

        me->add_temp("apply/attack", amount);
        me->add_temp("apply/defense", amount);
        me->delete_temp("cimu_power");
        me->delete_temp("pixie/cimu");
        tell_object(me, HIC"你的视力恢复过来了。\n"NOR);
}

