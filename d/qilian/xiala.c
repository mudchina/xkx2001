//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "夏拉");
        set("long", @LONG
抬眼望去，黄茫茫一片沙漠，似无尽头，直连天边。这里尽是
黄沙石砾，没有一点生气，蒙古语称为夏拉。
LONG
        );
        set("exits", ([
                "east" : __DIR__"gebi",
                "southeast" : __DIR__"yongchang",
		"north" :__FILE__,
		"south" :__FILE__,
		"west" :__FILE__,
        ]));


	set("cost", 5);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
