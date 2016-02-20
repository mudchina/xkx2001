//Cracked by Roath
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "谷口");
        set("long", @LONG
这里是山谷前面的一块平地。下山的路十分陡跷，而此地还时有
发生雪崩。
LONG
        );
        set("exits", ([
                "northdown" : __DIR__"xshan2",
                "southup" : __DIR__"shangu1",
        ]));
	switch(random(3)){
        case 1:
                set("objects", ([ "/d/xingxiu/npc/scorpion" : 1]));
                set("objects", ([ "/d/xingxiu/npc/centipede" : 1]));
                break;
        case 2:
                set("objects", ([ "/d/xingxiu/npc/centipede" : 1]));
                break;
        }

	set("cost", 2);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
