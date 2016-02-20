//Cracked by Roath
// /d/wanshou/liangongfang.c
// snowbird July 1999
// 1.1.1.1

#include "room.h"

inherit ROOM;

void create()
{
        set("short", "练功房");
        set("long", @LONG
万兽山庄弟子练功之所，房间的一侧放着兵器架，上面摆着各
种兵器。几个小弟子正比划着什么，切磋着武艺。
LONG
        );
        set("exits", ([
				"west" : __DIR__"qianting",
        ]));

	    set("cost", 0);
        setup();
        replace_program(ROOM);

}
