//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "铁石山");
        set("long", @LONG
这里是祁连山以西四十里处，山势峥嶙，通山一色漆黑，光秃秃的没
有一点生气。遍山尽是锘石，其色如墨，火烧成铁，制器极刚利。从这再
往西走，就进入北祁连山区了。
LONG
        );
        set("exits", ([
                "west" : __DIR__"zibai",
                "northwest" : __DIR__"ailao",
		"east" : __DIR__"qilian",
        ]));
	set("objects", ([
		__DIR__"obj/iron" : 2
	]));


	set("cost", 4);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
