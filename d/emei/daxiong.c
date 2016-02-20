//Cracked by Roath
// daxiong.c 大雄宝殿
// Shan: 96/06/29

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "华藏庵大雄宝殿");
	set("long", @LONG
这是峨嵋山华藏庵的大雄宝殿。正中供奉着普贤菩萨。一群青衣小师太正
在地上诵经。后面有道小门通往后殿。
LONG
	);

	set("exits", ([
		"northdown" : __DIR__"hz_guangchang",
		"south" : __DIR__"hz_back",
	]));

        create_door("south", "木门", "north", DOOR_CLOSED);

        set("valid_startroom",1);

	set("cost", 0);
	setup();
//	replace_program(ROOM);
}
