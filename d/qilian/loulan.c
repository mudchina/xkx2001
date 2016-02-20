//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "楼兰废墟");
        set("long", @LONG
当年楼兰王倾国力五载，修得这座楼兰城。后来楼兰王停止向汉朝进
贡，武帝遣霍去病平之，历时三载有余，屠尽楼兰之民，这里就成了一座
死城。后过百余年，楼兰城就消失了。据传埋于沙下，不知是否属实。
LONG
        );
        set("exits", ([
                "southwest" : __DIR__"sulee",
                "northeast" : __DIR__"jiuquan",
		"west" : "/d/qilian/yueerquan",
        ]));
	set("objects", ([
		"/d/xingxiu/npc/shachong" : 2,
	]));

	set("cost", 3);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
