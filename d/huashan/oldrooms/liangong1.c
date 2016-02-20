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
摆设，以免弟子行功时分心，耽误了进度。南边是男弟子休息室，北边有
扇木门通向东廊。
LONG
	);

	set("exits", ([
		"west" : __DIR__"zoulang1",
		"south" : __DIR__"nanshi",
		"north" : __DIR__"donglang",
	]));


	create_door("north", "木门", "south", DOOR_CLOSED);
	create_door("south", "竹门", "north", DOOR_CLOSED);
	
	set("cost", 0);
	setup();

//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ( (!myfam || myfam["family_name"] != "华山派") && dir == "south" )
                return notify_fail("华山不留外客，你不能住在这里！\n");

        if ( me->query("gender") == "女性" && dir == "south" && !wizardp(me) )
                return notify_fail("看清楚点，那是男弟子休息室！\n");

        if ( me->query("gender") == "无性" && dir == "south" )
                return notify_fail("你不能住在这里！\n");

        return ::valid_leave(me, dir);
}
