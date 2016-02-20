//Cracked by Roath
// sleeproom.c 华藏庵休息室
// Shan: 96/06/22

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "华藏庵休息室");
	set("long", @LONG
这里是峨嵋华藏庵的休息室。窗帘拉下来，房里整整齐齐放了很多木床。
有几个夜晚守庵的小师太正在睡觉。
　　休息室外就是禅房。
LONG
	);
	set("exits", ([
		"north" : __DIR__"hz_chanfang",
	]));

        set("item_desc",([
                "door"          :       (: look_door :),
        ]));

        create_door("north", "木门", "south", DOOR_CLOSED);

	set("no_fight", 1);
	set("sleep_room", 1);

	set("cost", 0);
	setup();
//	replace_program(ROOM);

}

