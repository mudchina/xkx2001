//Cracked by Kafei
// room: /d/city/forest1.c
// Jay 7/9/96

#include "tree.h"
 
void create()
{
    int i;
        set("short", "树林");
        set("long", @LONG
树林里光线暗淡，只能听见头顶上传来一些鸟儿的啼鸣。偶而从
茂密的叶间透过的一线光伴着落叶在飞舞。朽木腐烂的气味和身後传
来野兽的啸声使人不觉犹豫了前进的脚步。
LONG
        );

        set("exits", ([
                "southeast" : __DIR__"forest4",
		"west" : __DIR__"forest6",
		"northeast" : __DIR__"field1",
                "north" : "/d/taohuacun/taohua1",
        ]));

	set("objects", ([
		__DIR__"npc/mulang" : 1,
	]));

	set("climbup",__DIR__"tree11");

	set("cost", 3);
        setup();
}

