//Cracked by Roath
// Room: /d/shaolin/houyuan1.c
// xiaojian Aug.23,2000
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "厨房后院");
        set("long", @LONG
这是厨房的后院，院子里堆满了各种杂物，凌乱不堪,几乎
没有落脚之处,看来好久没人打扫了。
LONG
        );

        set("exits", ([
        "south" : __DIR__"chufang",
	     ]));

        set("outdoors", "shaolin");
        set("cost", 1);

        setup();
		replace_program(ROOM);
}
