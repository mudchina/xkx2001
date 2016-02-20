//Cracked by Roath
// /d/wanshou/shijie.c
// snowbird July 1999
// 1.1.1.1

#include "room.h"

inherit ROOM;

void create()
{
        set("short", "石阶");
        set("long", @LONG
你的眼前突然一亮，原来你已经走出了大森林，踏上一条蜿蜒
而上的青石阶。石阶两旁虽然仍郁郁葱葱地布满了树木，但已经不
象方才密林中那样阴森恐怖，仰头望去，山顶上白墙绿瓦一座山庄
一经清晰可见。
LONG
        );
        set("exits", ([
				"north" : __DIR__"frontgate",
				"south" : __DIR__"forest0",
        ]));

        set("outdoors", "wanshou-shanzhuang");

	    set("cost", 1);
        setup();
        replace_program(ROOM);

}
