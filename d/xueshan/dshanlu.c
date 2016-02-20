//Cracked by Roath
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "大雪山山路");
        set("long", @LONG
大雪山北麓的地势不是甚高，周围还有一些小山丘。西面有一
座寺院依山而建。显得异常高大。寺院呈平顶梯型，多由大石砌成，
墙体厚实，窗口窄小。 
LONG
        );
        set("exits", ([
                "westup" : __DIR__"shanmen",
                "north" : __DIR__"beilu",
        ]));
	set("objects", ([
		__DIR__"npc/tuying": 2,
		__DIR__"npc/lu" :1,
		__DIR__"npc/shui" : 1,
	]));

	set("cost", 3);
        setup();
        set("outdoors","qilian-shan");
}
int valid_leave(object me, string dir)
{
	if (dir =="westup" ) 
	me->set_temp("mark/comin", 1);

	return ::valid_leave(me, dir);
}
