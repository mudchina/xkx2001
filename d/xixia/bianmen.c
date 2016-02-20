//Cracked by Roath
// Room: /d/xixia/bianmen.c

inherit ROOM;
#include "room.h"
void create()
{
	set("short", "边门");
	set("long", @LONG
这里是皇宫的边门，供侍卫和内侍们出入之用，宫里所需的东西
一般都由此运入，因为比较偏僻，守卫的卫士也不多。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"chaifang",
  "east" : __DIR__"xiaolu3",
]));
	set("objects", ([
		__DIR__"npc/hgshi" : 2,
	]));
	create_door("west","木门","east",DOOR_CLOSED);	
	set("outdoors", "xixia");
	set("cost", 1);
	setup();
}
int valid_leave(object me, string dir)
{
        if (dir =="west") {
	if (present("wei shi", environment(me)))
                return notify_fail("卫士对你大吼一声：放肆！那不是你能进去的地方。\n");
	}	
        return ::valid_leave(me, dir);
}
