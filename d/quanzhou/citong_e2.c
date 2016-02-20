//Cracked by Roath
// citong_e2.c 刺桐东路
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "刺桐东路");
	set("long", @LONG
这是泉州的主要干道，笔直宽广，车水马龙，热闹非凡。恩怨巷坐落在北
边，可通至擂台。擂台比武可是城里的一大盛事。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"citong_e1", 
		"north" : __DIR__"enyuan",
	]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
