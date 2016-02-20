//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "博南山");
        set("long", @LONG
往北走，地面已渐渐地不再平坦，由丘陵地区转入山区。大路到此就
中断了，只剩坎坷不平的山路。再往北就是祁连山。南面是通向新城官道。
LONG
        );
        set("exits", ([
                "south" : __DIR__"guandao3",
                "north" : __DIR__"bulang-po",
        ]));


	set("cost", 3);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
