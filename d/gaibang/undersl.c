//Cracked by Roath
// Room: /d/gaibang/undersl.c
// Date: Haa 96/03/22

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "屋角边");
	set("long", @LONG
这是老乔家厨房大木柴堆下面。里面破破烂烂的，丢满了各种杂
物，还有丐帮弟子收集的破铜烂铁等。从这里通往丐帮的秘密通道。
LONG
	);

	set("exits", ([
		"up" : "/d/shaolin/chufang2",
		"southwest":__DIR__"slandao2",	
	]));

	set("objects",([
		CLASS_D("gaibang") + "/he-bujing" : 1,
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}



