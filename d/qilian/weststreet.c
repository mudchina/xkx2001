//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "西大街");
        set("long", @LONG
这是一条宽阔的青石板街道，向东西两头延伸。南面有一家小杂货铺。
LONG
        );
        set("exits", ([
                "west" : __DIR__"lanzhou-ximen",
                "east" : __DIR__"lanzhou",
		"south" :__DIR__"zahuopu",
		"north" :__DIR__"yangguan",
        ]));
	set("objects", ([
                "/d/village/npc/kid": 2,
	]));
	set("cost", 1);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
