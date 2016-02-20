//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "蒙古大草原");
        set("long", @LONG
一望无际的大草原上，成群的牛羊。稀稀落落有几处蒙古包。
LONG
        );
        set("exits", ([
                "north" : __DIR__"caoyuan4",
                "south" : __DIR__"caoyuan3",
		"west" :__DIR__"caoyuan3",
		"east" :__DIR__"caoyuan3",
        ]));


	set("cost", 3);
        setup();
	set("resource/grass", 1);
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
