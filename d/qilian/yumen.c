//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "玉门");
        set("long", @LONG
这里是西北的一处调兵站，北对蒙古，西卫青海，尤其是在汉代，玉
门是中原和西域间的一大要塞。北方是哈拉湖，西方是玉门关。
LONG
        );
        set("exits", ([
                "southup" : __DIR__"tanglang",
                "southwest" : __DIR__"jiayuguan",
		"north" :__DIR__"halahu",
        ]));


	set("cost", 2);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
