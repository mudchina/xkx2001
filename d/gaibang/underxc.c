//Cracked by Roath
// Room: /d/gaibang/undertree.c
// Date: Haa 96/03/22

#include <room.h>
inherit ROOM;




void create()
{
	set("short", "谷场槐树边");
	set("long", @LONG
这是谷场槐树边的谷堆，四周都是大谷堆。四周丢满了各种
杂物，还有丐帮弟子收集的破铜烂铁等。从这里通往丐帮的秘密
通道。
LONG
	);

	set("exits", ([
		"up" : "/d/village/square",
		"south":__DIR__"xcandao2",
	]));

	set("objects",([
		CLASS_D("gaibang") + "/ma-juwei" : 1,
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}



