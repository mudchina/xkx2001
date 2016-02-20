//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "羊肠小路");
        set("long", @LONG
眼前是一条一条羊肠小路，地处越来越偏僻，路径越来越隐秘。
LONG
        );
        set("exits", ([
                "west" : __DIR__"xiaolu",
                "north" : __DIR__"xiaolu3",
                "east" : __FILE__,
		"south" :__DIR__"xiaolu",
        ]));


	set("cost", 1);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
