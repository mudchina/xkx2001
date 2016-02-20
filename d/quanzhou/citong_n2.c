//Cracked by Roath
// citong_b1.c 刺桐北路
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "刺桐北路");
	set("long", @LONG
这是泉州的主要干道，笔直宽广，车水马龙，热闹非凡。西北方连着一条
巷子，可通往城隍庙。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"citong_n1",
		"south" : __DIR__"citong_n3",
		"northwest" : __DIR__"chxiang",
	]));

	set("objects", ([ 
                __DIR__"npc/liumang" : 2,
	]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
