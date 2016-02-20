//Cracked by Roath
//ts_pending.c
//xiaojian 06/2000
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
//void let_know(object me);

int update_condition(object me, int duration)
{
   object obj, *inv;
   int i, found;

        me->apply_condition("ts_pending", duration - 1);

        if( duration < 1 )
        {
                //call_out("let_know",1,me);
                return 0;
        }
        return CND_CONTINUE;
}
