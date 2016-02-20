//Cracked by Roath
// hz_back.c 华藏庵后殿 
// Shan: 96/06/29

#include <room.h>
inherit ROOM;

void create()
{
        set("short", " 华藏庵后殿");
	set("long", @LONG
这是峨嵋山华藏庵的后殿。是峨嵋派掌门人传教弟子功夫的地方。这里供
有一尊普贤菩萨像。两旁靠墙放着几张太师椅，地上放着几个蒲团。掌门人正
在向几个女弟子传授武功。
LONG
	);
	set("exits", ([
		"north" : __DIR__"daxiong",
	]));

        set("item_desc",([
                "door"          :       (: look_door :),
        ]));

        set("objects",([
                CLASS_D("emei") + "/miejue" : 1,
        ]));

        create_door("north", "木门", "south", DOOR_CLOSED);

	set("cost", 0);
	setup();
	replace_program(ROOM);

}
