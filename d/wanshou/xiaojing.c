//Cracked by Roath
// /d/wanshou/xiaojing.c
// snowbird July 1999
// 1.1.1.1

#include "room.h"

inherit ROOM;

void create()
{
        set("short", "青石小径");
        set("long", @LONG
一条青石铺成的小径，延伸到前面不远处一座高耸入云的山峰
下，山脚环绕着一片密林，山顶上绿阴掩映下隐隐露出屋檐的一角，
仿佛有人居住。
LONG
        );
        set("exits", ([
				"north" : __DIR__"shanjiao",
        ]));

        set("outdoors", "wanshou-shanzhuang");

	    set("cost", 1);
        setup();
        replace_program(ROOM);

}
