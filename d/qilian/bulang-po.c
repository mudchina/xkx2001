//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "不狼坡");
        set("long", @LONG
这里是祁连山脉的开始，地势复杂。山中多为人迹罕至之处，矿藏颇丰，
且山中有众多野生动物，是巡猎、访宝的好去处。
LONG
        );
        set("exits", ([
                "south" : __DIR__"bonan-shan",
                "north" : __DIR__"bulang-po2",
        ]));

	set("objects", ([
		"/d/forest/npc/mulang" : 1,
	]));

	set("cost", 3);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
