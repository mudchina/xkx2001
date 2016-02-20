//Cracked by Roath
// jiangfu.c 施琅将军府
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "施琅将军府");
	set("long", @LONG
这是一座气势恢宏的大宅院，琉璃瓦顶，飞檐斗拱，风格迥异。大红的正
门上方挂着一块横匾，上书四个金光闪闪的「靖海侯府」，乃是皇上所敕之宅，
以彰施琅将军攻破台湾的功绩。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"dxxiang",
		"south" : __DIR__"gtxiang",
		"north" : __DIR__"jiangfu1",
	]));

        set("objects", ([ 
		__DIR__"npc/wujiang" : 1,
                __DIR__"npc/bing" : 2,
        ]));

        set("no_clean_up", 0);

	set("cost", 1);
        setup();
}
int valid_leave(object me, string dir)
{
        if (objectp(present("guan bing", environment(me))) &&
                dir == "north")
                return notify_fail("官兵拦住了你的去路。\n");
	if (objectp(present("wu jiang", environment(me))) &&
                dir == "north")
                return notify_fail("武将拦住了你的去路。\n");
        return ::valid_leave(me, dir);
}
