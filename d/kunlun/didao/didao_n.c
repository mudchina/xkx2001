//Cracked by Roath
// Room: didao_n.c 地道北
// Zhangchi 7/00

inherit ROOM;
#include "didao.h"

void create()
{
	set("short", "地道");
	set("long", @LONG
这是一条刚刚挖成的地道，看样子是往北延伸。
LONG
	);
	set("exits", ([
		"south": __DIR__"didao1",
]));
	set("no_clean_up", 1);
	set("cost", 1);
	set("valid_dig","north");

	setup();
//	replace_program(ROOM);
}

void init()
{
	int num=get_room("north");
	if (num >= 1)
		set("exits/north",__DIR__"didao_n_1");
	else
		delete("exits/north");

	add_action("do_dig","wa");
	add_action("do_dig","dig");
}