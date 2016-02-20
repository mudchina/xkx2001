//Cracked by Roath
//tiaoshui.c
//xiaojian 06/2000
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
void let_know(object me);

int update_condition(object me, int duration)
{
   object obj, *inv;
   int i, found;

        me->apply_condition("tiaoshui", duration - 1);

        if( duration < 1 )
        {
                call_out("let_know",1,me);
                return 0;
        }
        return CND_CONTINUE;
}
void let_know(object me)
{
	tell_object(me, HIG "你时间已到，任务失败！\n" NOR);
	
}