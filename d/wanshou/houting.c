//Cracked by Roath
// /d/wanshou/houting.c
// snowbird July 1999
// 1.1.1.1

#include "room.h"

inherit ROOM;

void create()
{
        set("short", "后厅");
        set("long", @LONG
后厅的面积相当大，是二庄主管见子史仲猛授徒之所，后厅四
侧的墙壁上绘着虎豹狮象猴五种动物嬉戏搏斗的图形，栩栩如生，
几个山庄的弟子正聚精会神地看着图形琢磨着什么。
LONG
        );
        set("exits", ([
                "south" : __DIR__"zhenting",
                "east" : __DIR__"bedroom",
        ]));

	    set("cost", 0);
        setup();
        replace_program(ROOM);

}
