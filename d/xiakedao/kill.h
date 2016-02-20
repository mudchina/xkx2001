//Cracked by Roath
#include <ansi.h>

int do_kill(string arg)
{
  /*
	object target;
	object killer;
	object me = this_player();
	if( !arg )
		return notify_fail("你想杀谁？\n");
      if( environment(me)->query("no_fight") )
		return notify_fail("这里不能打架。\n");
	if(!objectp(target = present(arg, environment(me))))
		return notify_fail("这里没有这个人。\n");
	if(me == target)
		return 0;
	if( !target->is_character() || target->is_corpse() )
		return notify_fail("看清楚一点，那并不是活物。\n");

	if( !userp(target) )
	{	return 0;
	}

	killer=new(__DIR__"npc/dizi");
	killer->set("xkd/killer", me->query("id"));
	killer->move(environment(target));
	message_vision("$N走了过来。\n" NOR, killer);
	*/
	return 0;
}

