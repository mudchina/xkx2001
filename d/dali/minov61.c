//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov61.c

inherit ROOM;

void create()
{
	set("short", "河上");
	set("long", @LONG
你正身处波涛滚滚的泸水之上百多尺的空中。这是一座乌夷族特有之藤桥，
三根粗大的藤条呈一个倒“品”字形，脚踩下面一条，手扶左右两条，攀援而过
看来惊险，实际上倒也不十分困难。一阵山风挟着脚下激流飞溅的水花吹过，你
感到一阵寒意。
LONG);
	set("exits", ([
		"west" : __DIR__"minov60",
		"east" : __DIR__"minov85",
		]));
	set("area", "剑川镇");
	set("cost", 50);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
