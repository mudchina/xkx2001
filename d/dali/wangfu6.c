//Cracked by Roath
// Room: /d/dali/wangfu6.c

inherit ROOM;

void create()
{
	set("short", "观妙亭");
	set("long", @LONG
这是一座小小，四周景色秀丽，恬静宜人。亭子里有一张石桌，几张石凳，
供游人休息。旁边古树参天，花草丛中蝴蝶纷飞，不时还可以看到几只小兽从旁
边跑过。
LONG);
	set("exits", ([
		"north" : __DIR__"wangfu7.c",
		"east" : __DIR__"wangfu3.c",
		]));
	set("cost", 1);
	set("wangfu", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
