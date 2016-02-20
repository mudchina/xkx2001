//Cracked by Roath
// Room: /d/dali/shanlu2.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
一条山路，两边是茂密的树林，西面是延绵不绝的大山，南面是一望无际的
西双版纳大森林，传说有邪教教众在其中活动。道路两旁间或可见一些夷族的村
镇。山路转向东蜿蜒着。
LONG);
	set("objects", ([
		__DIR__"npc/snbz": 1,
		]));
	set("exits", ([
		"northwest" : __DIR__"shanlu1.c",
		"eastdown" : __DIR__"shanlu3.c",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
