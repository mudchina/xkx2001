//Cracked by Roath
// halt.c
// By Xiang@XKX (12/17/95)

int main(object me, string arg)
{
        if (me->is_fighting()) {
                me->remove_all_enemy();
                message_vision("$N身行向后一跃，跳出战圈不打了。\n", me); 
        }
        else if (!me->is_busy()) 
                return notify_fail("你现在不忙。\n");
        else if ((int)me->query_temp("pending/exercise") != 0) {
                message_vision("$N把正在运行的真气强行压回丹田，站了起来。\n", me);
                me->interrupt_me();
        }
        else if ((int)me->query_temp("pending/respirate") != 0) {
                message_vision("$N猛吸几口大气，站了起来。\n", me);
                me->interrupt_me();
        } 
        else if ((int)me->query_temp("pending/jingzuo") != 0) {
                message_vision("$N心烦意乱，睁开眼睛站了起来。\n", me);
                me->interrupt_me();
        }

        me->interrupt_me();
	// if (me->is_busy()) write("你现在很忙，停不下来。\n");
	
        return 1;
}
        
