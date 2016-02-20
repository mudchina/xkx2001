//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "兰州西门");
        set("long", @LONG
这是兰州西城门，望西走五十里的官道便是新城。
LONG
        );
        set("exits", ([
                "east" : __DIR__"weststreet",
                "west" : __DIR__"guandao1.c",
        ]));


	set("cost", 1);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
