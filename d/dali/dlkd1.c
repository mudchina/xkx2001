//Cracked by Roath
// Room: /d/dali/dlkd1.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"客店"NOR);
	set("long", @LONG
这是喜州城里唯一的一家客栈，专门接待过往客商，生意非常兴隆。店小二
里里外外忙得团团转。此间虽偏远，却不因势坑宰客人，住店一宿只要五两银子。
LONG);
	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
		]));
	set("exits", ([
		"west" : __DIR__"minov64",
		"up" : __DIR__"dlkd2",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	set("valid_startroom", 1);
	setup();
}
int valid_leave(object me, string dir)
{
	string id;
	int i;

	if(me == present("xiao er"))
		return ::valid_leave(me, dir);

	if(objectp(present("xiao er", environment(me))))
	{
		if ( !me->query_temp("rent_paid") && dir == "up" )
			return notify_fail("店小二一下挡在楼梯前，白眼一翻：怎麽着，想白住啊！\n");
		if ( me->query_temp("rent_paid") && dir != "up" )
			return notify_fail("店小二跑到门边拦住：客官已经付了银子，怎麽不住店就走了呢！旁人还以为小店伺候不周呢！\n");
	}
	return ::valid_leave(me, dir);
}
