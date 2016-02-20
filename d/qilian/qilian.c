//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "祁连山");
        set("long", @LONG
祁连山为南祁连山脉的最高峰，海拔五千二百多米，山势挺拔，为西北起酒
泉，东南至古浪的第一山。山野遍是奇石，为西北一大奇观，与东南方马鬃山遥
对。山中据闻时有仙人据石对弈.
LONG
        );
        set("exits", ([
                "southeast" : __DIR__"niaoju",
                "east" : __DIR__"mazong",
		"west" : __DIR__"tieshi",
        ]));


	set("cost", 3);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
