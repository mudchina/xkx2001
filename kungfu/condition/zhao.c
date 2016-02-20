//Cracked by Roath
//zhao.c for ding-force
//inc defence power while dec neili continuely

void remove_effect(object me, int amount);

int update_condition(object me, int duration)
{
	int lv, dur, drop;

        lv = (int)me->query_skill("ding-force", 1);
        dur = (int)me->query("neili");

	if( !me->is_fighting())
	{
		remove_effect(me, lv);
		return 0;
	}

	if (lv >150) {
                drop = 200 * 150 / lv;
                dur = (dur - drop)/drop;
		if (dur < 1) {
			remove_effect(me, lv);
			 return 0;
		}
	}
//add other lvs later
	
	me->add("neili", -drop);

	me->apply_condition("zhao", dur);
	return 1;
}

void remove_effect(object me, int amount)
{
        object *inv;
	int i;

        inv = all_inventory(me);
	for (i=0; i<sizeof(inv); i++) {
                if ((string)inv[i]->query("id")=="huti shengong") 
		destruct(inv[i]);
	}
	me->delete_temp("huti");
       tell_object(me, "你的金钟罩护体功运行完毕，将内力收回丹田。\n");
}


