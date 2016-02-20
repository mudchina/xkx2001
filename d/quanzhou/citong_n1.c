//Cracked by Roath
// citong_n1.c 刺桐北路
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "刺桐北路");
	set("long", @LONG
这是泉州的主要干道，笔直宽广，车水马龙，热闹非凡。东边是都督巷，
可通往都督府。一队队的士兵穿来插去，把守森严。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"east" : __DIR__"duxiang",
		"north" : __DIR__"weiyuan",
		"south" : __DIR__"citong_n2",
	]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
