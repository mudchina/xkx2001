//Cracked by Roath
// Room: /d/dali/dalicheng6.c

inherit ROOM;

void create()
{
	set("short", "薛记成衣铺");
	set("long", @LONG
这是一家老字号的估衣庄，里面摆满了各式各样的衣物。绸、绢、丝、布、
皮袄、大红斗蓬、葱黄绫子棉裙、水绿色棉袄，秋香色团花。。。不一而足。
LONG);
	set("objects", ([
		__DIR__"npc/bossxue" : 1,
		]));
	set("exits", ([
		"south" : __DIR__"dalicheng5",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
