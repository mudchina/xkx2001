//Cracked by Roath
// yideng quest room 3

inherit ROOM;
int do_jump(string);

void create()
{
	set("short", "瀑布下");
	set("long", @LONG
这里是瀑布水底，水流急冲直下，你双足使劲，以「千斤坠」的功夫牢牢站
稳，恰似中流砥柱，崎立不动。
LONG);
	set("objects", ([
		__DIR__"npc/gfish" : 1,
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	set("invalid_startroom", 1);
	setup();
}
void init()
{
	add_action("do_jump", "jump");
}
int do_jump(string arg)
{
	object me = this_player();

	if ( !arg || arg != "bank" ) return notify_fail( "什么？\n");

	message_vision("$N纵身往岸上跳去。\n", me);
	me->move(__DIR__"yideng1");
	return 1;
}

