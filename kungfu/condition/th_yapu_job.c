//Cracked by Roath

#include <login.h>

int update_condition(object me, int duration)
{
        if (duration < 1) return 0;
        me->apply_condition("th_yapu_job", duration - 1);
        return 1;
}

