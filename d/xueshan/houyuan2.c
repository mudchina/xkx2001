//Cracked by Roath
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "后院");
        set("long", @LONG
这里是后院，东边墙脚下有一口水井(well)，南面是拉章别院。
LONG
        );
        set("exits", ([
                "south" : __DIR__"lazhang",
		"west" :__DIR__"houyuan",
        ]));
	set("objects", ([
		"/clone/weapon/falun": 1,
	]));
	set("item_desc", ([
                "well" : "这是一口水井。\n"
        ]));
        set("resource/water", 1);

	set("cost", 1);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
