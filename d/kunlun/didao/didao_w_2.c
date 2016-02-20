//Cracked by Roath
// Room: didao_w_2.c 地道西
// Zhangchi 7/00

inherit ROOM;
#include "didao.h"

void create()
{
	set("short", "地道");
	set("long", @LONG
这是一条刚刚挖成的地道，看样子是往西延伸。
LONG
	);
	set("exits", ([
		"east": __DIR__"didao_w_1",
]));
	set("no_clean_up", 1);
	set("cost", 1);
	set("valid_dig","west");

	setup();
//	replace_program(ROOM);
}

void init()
{
	int num=get_room("west");
	if (num >= 3)
		set("exits/west",__DIR__"didao_w_3");
	else
		delete("exits/west");

	add_action("do_dig","wa");
	add_action("do_dig","dig");
}

