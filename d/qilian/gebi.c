//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "戈壁");
        set("long", @LONG
抬眼望去，黄茫茫一片沙漠，似无尽头，直连天边，本处沙土质潮，
地下尚有藏水，眼中仍可见些许枯黄沙草。永昌的驻军时有来此打个沙
兔、沙狼什么的。
LONG
        );
        set("exits", ([
                "north" : __DIR__"gebi1",
                "south" : __DIR__"yongchang",
		"east" :__FILE__,
		"west" :__FILE__,
        ]));
	set("objects", ([
                "/d/xingxiu/npc/shachong" : 1,
        ]));


	set("cost", 4);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
