//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "碎石沙路");
        set("long", @LONG
你走在一条荒僻的碎石沙路上，东北面有一座雄伟的关隘，西南通
向酒泉。
LONG
        );
        set("exits", ([
                "southwest" : __DIR__"jiuquan",
                "northeast" : __DIR__"shalu",
        ]));

	set("objects", ([
		"/d/xingxiu/npc/spider" : 2,
	]));

	set("cost", 1);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
