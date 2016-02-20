//Cracked by Roath
// citong_x1.c 刺桐西路
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "刺桐西路");
	set("long", @LONG
这是泉州的主要干道，笔直宽广，车水马龙，热闹非凡。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
	]));

        set("objects", ([ 
        ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
