//Cracked by Roath
// xs_necromancy.c
// snowbird, 1999
// 1.1.1.1

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
void del_sung(object me);

int update_condition(object me, int duration)
{
   object obj, *inv;
   int i, found;

//    message("vision", me->name() + "is beening controlled\n", environment(me), me);
    me->set_temp("block_msg/all", 1);
	me->apply_condition("xs_necromancy", duration - 1);

	if( duration < 1 )
	{
		call_out("del_sung",1,me);
		return 0;
	}
	return CND_CONTINUE;
}

void del_sung(object me)
{
	object link_ob;

    if ( me->query("xueshan/necromancy_singer") )
       me->delete("xueshan/necromancy_singer");
	if (!me) return;
//	if (me->query_temp("cursed", 1))
//	me->set_temp("cursed", 0);
	if (me->query_temp("block_msg/all", 1))
	me->set_temp("block_msg/all", 0);
	if (me->query_leader() ) 
        me->set_leader(0);	
	message_vision("$N慢慢地清醒过来，魂魄又回到了自己身体上。\n", me);


    me->remove_all_killer();
}


