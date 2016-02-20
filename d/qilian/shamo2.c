//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "戈壁");
        set("long", @LONG
抬眼望去，黄茫茫一片沙漠，似无尽头, 直连天边，本处沙土质潮，
地下尚有藏水，眼中仍可见些许枯黄沙草。
LONG
        );
        set("exits", ([
                "north" : __DIR__"caoyuan1",
                "south" : __DIR__"xiala1",
		"east" :__DIR__"xiala1",
		"west" :__DIR__"xiala1",
        ]));


	set("cost", 5);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
