//Cracked by Roath
// Room: /d/gaibang/xcandao2.c
// Date: Haa 96/03/22

#include <room.h>
inherit ROOM;




void create()
{
	set("short", "暗道");
	set("long", @LONG
这是丐帮 极其秘密的地下通道，乃用丐帮几辈人之心血掘成。 
LONG
	);

	set("exits", ([
			"north" : __DIR__"underxc",
			"south" : __DIR__"xcandao1",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}



