//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "青石官道");
        set("long", @LONG
你走在一条青石官道上，来往行人逐渐稀少，北行二十余里，便是
博南山区了。
LONG
        );
        set("exits", ([
                "south" : __DIR__"xincheng",
                "north" : __DIR__"bonan-shan",
        ]));


	set("cost", 1);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
