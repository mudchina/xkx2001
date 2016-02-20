//Cracked by Roath
// citong_s1.c 刺桐南路
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "刺桐南路");
	set("long", @LONG
这是泉州的主要干道，笔直宽广，车水马龙，热闹非凡。刺桐南路的东边
是打锡巷，西边有一大片民宅，四通八达，连着武馆和戏院。北边便是热闹的
中心广场。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"zhongxin",
		"south" : __DIR__"citong_s2",
		"east" : __DIR__"dxxiang",
		"west" : __DIR__"minzai1",
		"southwest" : __DIR__"minzai2",
	]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
