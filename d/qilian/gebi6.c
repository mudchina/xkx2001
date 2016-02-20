//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "戈壁");
        set("long", @LONG
抬眼望去，黄茫茫一片沙漠，似无尽头, 直连天边，本处沙土质潮，
地下尚有藏水，眼中仍可见些许枯黄沙草。永昌的驻军时有来此打个沙
兔、沙狼什么的。
LONG
        );
        set("exits", ([
                "north" : __DIR__"gebi4",
                "south" : __DIR__"gebi3",
		"east" :__DIR__"gebi7",
		"west" :__DIR__"gebi2",
        ]));


	set("cost", 5);
	set("outdoors","qilian-shan");
        setup();
	replace_program(ROOM);
}

