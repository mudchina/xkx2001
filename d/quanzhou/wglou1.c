//Cracked by Roath
// wglou1.c 万国烟雨楼
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "万国烟雨楼");
	set("long", @LONG
「人道不思归，烟雨伴君眠」，傍湖而建，情趣盎然的万国烟雨楼名虽酒
楼，实是远近闻名的一景。楼分两层，一进大门，即可见园林中亭台楼榭，假
山流水，一池碧水，荷藕映红。环池漫步，客房绵延。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"up" : __DIR__"wglou2.c",
		"west" : __DIR__"jiedao2.c",
	]));

        set("objects", ([ 
		__DIR__"npc/qzxiaoer" : 1,
        ]));

        set("no_clean_up", 0);

	set("cost", 1);
        setup();
	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        if( present("xiao er", me) && dir="west" )
                return notify_fail("好端端地你想带店小二到那里去？！\n");

        return ::valid_leave(me, dir);
}
