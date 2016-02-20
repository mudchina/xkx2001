//Cracked by Roath
// chxiang.c 城隍巷
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "城隍巷");
	set("long", @LONG
一条弯曲狭窄的碎石小路，两旁树木参差，阴暗森冷。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"southeast" : __DIR__"citong_n2",
		"northwest" : __DIR__"chmiao",
	]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
