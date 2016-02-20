//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "马鬃山");
        set("long", @LONG
马鬃山状如其名，山脉绵长，山峰岑差不齐，挽似野马之鬃。听老人们讲，
凡心诚而善入山者，可得宝藏而归，但凡为富不仁进山者，必难生还。
LONG
        );
        set("exits", ([
                "southdown" : __DIR__"niaoju",
                "west" : __DIR__"qilian",
        ]));


	set("cost", 3);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
