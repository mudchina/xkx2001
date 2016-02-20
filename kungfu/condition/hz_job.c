//Cracked by Roath
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   me->apply_condition("hz_job", duration - 1);

   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}                                                                                                                