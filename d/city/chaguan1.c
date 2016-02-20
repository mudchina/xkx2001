//Cracked by Roath
// Room: /city/chaguan.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "春来茶馆");
	set("long", @LONG
你一走进来，就闻到一股茶香沁入心脾，精神为之一爽。几张八仙桌一字排
开，坐满了客人，或高声谈笑，或交头接耳。你要想打听江湖掌故和谣言，这里
是个好所在。
LONG
	);
	set("resource/water", 1);

	set("exits", ([
		"east" : __DIR__"nandajie3",
	]));

	set("objects", ([
		__DIR__"npc/aqingsao" : 1,
	]));

	set("cost", 0);
	setup();
	replace_program(ROOM);
}

