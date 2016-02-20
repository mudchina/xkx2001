//Cracked by Roath
// shuiguan.c 涂门水关
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "涂门水关");
	set("long", @LONG
这是去往港口的主要通道，横跨小溪之上，巍然矗立，可谓巧手天成，别
具一格。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"east" : __DIR__"lingmu",
		"west" : __DIR__"tumen",	
	]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
