//Cracked by Roath
// cangjing.c 后山门
// qfy Nov 3, 1996

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "后山门");
	set("long", @LONG
这是藏经阁后，东北边有扇小门。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"northeast" : __DIR__"chmiao",
		"southup" : __DIR__"cangjing",
	]));

        set("objects", ([ 
        ]));

	create_door("northeast", "小门", "southwest", DOOR_CLOSED);

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
