//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "蒙古大草原");
        set("long", @LONG
突然一阵清新的草风向你迎面吹来，终於走出了戈璧，出现在你眼前
的是一片一望无际的大草原。
LONG
        );
        set("exits", ([
                "north" : __DIR__"caoyuan2",
                "south" : __DIR__"shamo2",
		"west" :__DIR__"caoyuan3",
        ]));


	set("cost", 3);
	set("resource/grass", 1);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
