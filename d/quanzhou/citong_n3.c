//Cracked by Roath
// citong_b1.c 刺桐北路
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "刺桐北路");
	set("long", @LONG
这是泉州的主要干道，笔直宽阔，车水马龙，热闹非凡。南面是热闹喧哗
的中心广场，嘈杂的声音远远便能听到。东边有家鸿福楼。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"citong_n2",
		"south" : __DIR__"zhongxin",
		"east" : __DIR__"qzkedian",
	]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
