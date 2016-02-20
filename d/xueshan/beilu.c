//Cracked by Roath
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "大雪山北麓");
        set("long", @LONG
这里山势比大雪山东面稍缓，也不是十分的严寒。山道两
旁长得有稀稀拉拉的一些野草。四下毫无人迹，只有几只秃鹰
在高处盘旋，俯视着茫茫雪山。
LONG
        );
        set("exits", ([
                "eastdown" : __DIR__"shanlu2",
                "south" : __DIR__"dshanlu",
        ]));
	set("objects", ([
__DIR__"npc/hua" : 1,
        ]));

	set("cost", 3);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
