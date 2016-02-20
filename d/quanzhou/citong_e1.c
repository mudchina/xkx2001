//Cracked by Roath
// citong_e1.c 刺桐东路
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "刺桐东路");
	set("long", @LONG
这是泉州的主要干道，笔直宽广，车水马龙，热闹非凡。北边的粮仓里有
士兵把守，以防贼盗洗劫。往东可至恩怨巷，再到擂台。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"liangcang",
		"west" : __DIR__"zhongxin",
		"east" : __DIR__"citong_e2",
	]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
