//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "蒙古大草原");
        set("long", @LONG
一望无际的大草原上，成群的牛羊。前面是一个大於一般蒙古包五六倍的庞
然巨物，由十六根大柱子撑起来的大帐棚。
LONG
        );
        set("exits", ([
                "south" : __DIR__"caoyuan3",
		"west" :__DIR__"caoyuan3",
		"east" :__DIR__"caoyuan3",
		"enter" :__DIR__"bao",
        ]));
	set("objects", ([
                "/d/qilian/npc/meng-shi1.c" : 4,
        ]));

	set("cost", 3);
        setup();
	set("resource/grass", 1);
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
