//Cracked by Roath
// hjting.c 花桥亭
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "花桥亭");
	set("long", @LONG
这是一个建在大路中央的小亭子，三三两两的行人在此休息。南去便是顺
济桥，可通往港口。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"jishi",
		"south" : __DIR__"sjqiao",
	]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
