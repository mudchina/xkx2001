//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov19.c

inherit ROOM;

void create()
{
	set("short", "沿池小路");
	set("long", @LONG
这是一条沿着滇池南岸的小路，柳荫夹岸，清风袭人。远望滇池湖面，碧波
荡漾，飞鸟戏水，遥遥可见游船、渔船轻帆浮云。端地是人间仙境。此路向西直
上滇池西岸的群山。
LONG);
	set("exits", ([
		"westup" : __DIR__"minov7",
		"east" : __DIR__"minov18",
		]));
	set("area", "罗伽甸");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
