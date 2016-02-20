//Cracked by Roath
// bandaged.c

#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        if( (int)me->query("eff_jing") < (int)me->query("max_jing") )
                me->receive_curing("jing", 4);

        me->apply_condition("jing_curing", duration - 1);
        if( !duration ) return 0;

        return CND_CONTINUE;
}
