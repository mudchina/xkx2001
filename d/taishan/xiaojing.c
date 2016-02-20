//Cracked by Roath
// xiaojing2.c 小径
// qfy July 12, 1996

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "小径");
        set("long", @LONG
一条里许长的小径，远处有座峭壁，风景甚佳。
LONG
        );

	set("exits", ([
		"east" : __DIR__"dongqian",
		"west" : __DIR__"qiaobi0",
        ]));

	set("cost", 1);
        setup();
}

void init()
{
	this_player()->set_temp("marks/小", 1);
}
