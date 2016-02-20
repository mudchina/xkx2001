//Cracked by Roath
// sjqiao.c 顺济桥
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "顺济桥");
	set("long", @LONG
这是横跨晋河的一座石拱桥。桥宽水深，水陆交通便捷，是南去的唯一出
口。一队官兵驻扎在这里。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"hjting",
		"south" : __DIR__"gangkou1",
		"southeast" : __DIR__"shijiefu",
	]));

        set("objects", ([ 
		__DIR__"npc/bing" : 2,
		__DIR__"npc/wujiang" : 1,
        ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
