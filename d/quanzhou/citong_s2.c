//Cracked by Roath
// citong_s1.c 刺桐南路
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "刺桐南路");
	set("long", @LONG
这是泉州的主要干道，笔直宽广，车水马龙，热闹非凡。由此东行便到承
天寺，西边是民宅，西南则是一处阿拉伯宅区。泉州出名的源和堂便在西边。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"east" : __DIR__"chengtian",
		"west" : __DIR__"minzai3",
		"north" : __DIR__"citong_s1",
		"southeast" : __DIR__"alabo",
	]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
