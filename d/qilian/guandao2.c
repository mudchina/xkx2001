//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "青石官道");
        set("long", @LONG
你走在一条青石官道上，人来人往非常繁忙，不时地有人骑着马匆匆而过。
大道两旁有一些小货摊，似乎是一处集市。西面通向新城。
LONG
        );
        set("exits", ([
                "east" : __DIR__"guandao1",
                "west" : __DIR__"xincheng",
        ]));


	set("cost", 1);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
