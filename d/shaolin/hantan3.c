//Cracked by Roath
// Room: /d/shaolin/hantan3.c

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "万古寒潭");
	set("long", @LONG
这是寒潭之中。冰与水混合在一起，使整个潭水在此处变得
跟稀粥一样，身周的冰壳已凝成一个大块，除了双眼尚能透过冰
层视物外，全身各处都已动弹不得，只能听任水流带你继续往下
沉去。
LONG
	);

	set("cost", 3);
	setup();
}

void init()
{
	call_out("down", 10, this_player());
}

void down(object me)
{
	tell_object(me, HIR "\n突然一股无比巨大的寒流如巨锤般迎面扑来，你顿时昏了过去 ... \n\n" NOR);
	me->set_temp("block_msg/all", 1);
	me->unconcious();
	me->move("/d/kunlun/river1");
}
