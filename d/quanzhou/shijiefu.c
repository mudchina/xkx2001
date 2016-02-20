//Cracked by Roath
// shijiefu.c 市舶司
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "市舶司");
	set("long", @LONG
这是负责接待海外使节及筹备出海西洋必要手续的地方。门口左右两边各
有一个青石狮子，形态矫健，仰天高吼。西北边通往顺济桥，西南边通往港口
路，北边的街道尽头则是涂门集。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"jiedao2",
		"northwest" : __DIR__"sjqiao",
		"southwest" : __DIR__"gangkou1",
	]));

        set("objects", ([ 
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
        ]));

        set("no_clean_up", 0);

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
