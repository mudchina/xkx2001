//Cracked by Roath
// liangong1.c 练功房
// by qfy

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "练功房");
	set("long", @LONG
练功房是供华山弟子修练内功，或研读武学书籍之处。房内并无特别
摆设，以免弟子行功时分心，耽误了进度。东边是男弟子休息室。
LONG
	);

	set("exits", ([
		"west" : __DIR__"pianting2",
		"east" : __DIR__"nanshi",
		"north" : __DIR__"zoulang2",
	]));


	create_door("north", "木门", "south", DOOR_CLOSED);
	create_door("east", "竹门", "west", DOOR_CLOSED);
	
	set("cost", 0);
	setup();

//      replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if ( me->query("gender") == "女性" && dir == "east" && !wizardp(me) )
		return notify_fail("看清楚点，那是男弟子休息室！\n");

	return ::valid_leave(me, dir);
}