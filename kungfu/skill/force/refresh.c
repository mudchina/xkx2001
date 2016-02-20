//Cracked by Roath
// refresh.c
// modified by sdong for one time yun refresh max to avoid flooding

//inherit SSERVER;

int exert(object me, object target)
{
        int n,q;
	if (target != me) 
		return notify_fail("你只能用内功恢复自己的精力。\n");
	
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够。\n");

	if ((int)me->query("jingli") >= (int)me->query("max_jingli") )
		return notify_fail("你现在精力充沛。\n");

        q = (int)me->query("max_jingli") - (int)me->query("jingli");
	if ( q < 10) return notify_fail ("你现在精力充沛。\n");

        n = 100 * q / me->query_skill("force");
        if (n < 20)
                n = 20;
        if ((int)me->query("neili") < n) {
                q = q * (int)me->query("neili") / n;
                n = (int)me->query("neili");
        }

        me->add("neili", -n);
        me->receive_heal("jingli", q);

	
        message_vision("$N伸了伸腰，长长地吸了口气。\n", me);

        if( me->is_fighting() ) me->start_busy(1);
	
	return 1;
}

