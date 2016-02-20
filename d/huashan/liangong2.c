//Cracked by Roath
// liangong2.c 练功房
// by qfy

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "练功房");
	set("long", @LONG
练功房是供华山弟子修练内功，或研读武学书籍之处。房内并无特别
摆设，以免弟子行功时分心，耽误了进度。西边是女弟子休息室。
LONG
	);

	set("exits", ([
		"east" : __DIR__"pianting2",
		"west" : __DIR__"nushi",
		"north" : __DIR__"zoulang4",
	]));

	set("cost", 0);
	setup();

	create_door("north", "木门", "south", DOOR_CLOSED);
	create_door("west", "竹门", "east", DOOR_CLOSED);

//      replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ( me->query("gender") == "男性" && dir == "west" && !wizardp(me) )
		return notify_fail("看清楚点，那是女弟子休息室！\n");

	return ::valid_leave(me, dir);
}
