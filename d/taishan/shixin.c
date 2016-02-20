//Cracked by Roath
// Room: /d/taishan/.c
// Date: CSWORD 96/03/25
// modified by qfy July 13, 1996.

inherit ROOM;

void create()
{
	set("short", "试心石");
	set("long", @LONG
这里便是莲花峰的峰顶，由两块巨石勾连在一起，据说若果你
心存诚意，登上试心石时石快便不会动摇，反之则摇动不止。
LONG
	);

	set("exits", ([
		"southdown" : __DIR__"lianhua",
	]));

	set("outdoors", "taishan");
	set("cost", 2);
	setup();
}

void init()
{
	object me = this_player();
	int check, wait_time = 0;

        me->delete_temp("marks/墓");
        me->delete_temp("marks/跪");
	me->delete_temp("marks/墙");
	me->delete_temp("marks/小");

	if ( me->query_temp("marks/风") && interactive(me) && !me->is_fighting() ) {
           call_out("open_up", 1200, me);
	}
}

int open_up(object me)
{
        message_vision("$N心诚意真地等了良久，突然大地一阵震动，两块试心石分\n", me);
	message_vision("裂开来，露出一条窄窄的密径。\n", me);
	me->set_temp("marks/等", 1);
	set("exits/enter", __DIR__"mijing");
	call_out("close_up", 5, me);
	return 1;
}

int close_up(object me)
{
	message_vision("又是一阵山摇地动，两块试心石逐渐合拢起来。\n", me);
	delete("exits/enter");
	me->delete_temp("marks/等");
	return 1;
}

int valid_leave(object me, string dir)
{
	if ( !me->query_temp("marks/等") && dir == "enter" )
	   return notify_fail("你心意不诚，不能进入密径。\n");
	else if ( me->query_temp("marks/风") && dir == "southdown" ) {
	   remove_call_out("open_up");
	}

	return ::valid_leave(me, dir);
}
