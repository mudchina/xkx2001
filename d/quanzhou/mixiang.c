//Cracked by Roath
// mixiang.c 米仓巷
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "米仓巷");
	set("long", @LONG
这是通往粮仓的小路。由于民间匪盗经常抢劫官府粮仓，都督府震怒之下，
特开此路以利府中官兵增援粮仓。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"dufu",
		"southwest" : __DIR__"liangcang",
	]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
