//Cracked by Roath
// /kungfu/condition/biao.c
// sdong, 12/12/98

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
void let_know(object me);

int update_condition(object me, int duration)
{
   object obj, *inv;
   int i, found;

	me->apply_condition("biao", duration - 1);

	if( duration < 1 )
	{
		call_out("let_know",1,me);
		return 0;
	}
	return CND_CONTINUE;
}

void let_know(object me)
{
		  tell_object(me, HIG "你终于恢复了一点自信！\n" NOR);
}
