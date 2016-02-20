//Cracked by Roath
// citong_x1.c 刺桐西路
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "刺桐西路");
	set("long", @LONG
这是泉州的主要干道，笔直宽广，车水马龙，热闹非凡。西边便是著名的
开元寺及西门吊桥。北边有一家杂货铺，专卖女人家用的东西。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"citong_w2",
		"east" : __DIR__"zhongxin",
		"north" : __DIR__"zahuopu",
	]));

        set("objects", ([ 
        ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if ( dir == "north" && me->query("gender") == "男性" && !wizardp(me) )
		return notify_fail("你一个大男人到女人店里去想干什么？\n");

	return ::valid_leave(me, dir);
}
