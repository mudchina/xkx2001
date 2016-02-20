//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "螳螂岭");
        set("long", @LONG
这里是祈连山区边缘。出了螳螂岭往西就是西北平原，北至玉门，西到
嘉峪关。螳螂岭山形漫长，山势低矮，再加上通山翠绿，四季不变，故而得
名。
LONG
        );
        set("exits", ([
                "west" : __DIR__"jiayuguan",
                "northdown" : __DIR__"yumen",
                "eastup" : __DIR__"qitian",
        ]));


	set("cost", 4);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
