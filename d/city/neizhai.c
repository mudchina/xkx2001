//Cracked by Roath
// Room: /city/neizain.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "内宅");
	set("long", @LONG
这里是衙门的内宅，住着提督的家眷。外人到此就该止步了。
LONG
	);

	set("exits", ([
		"north" : __DIR__"ymzhengting",
	]));
	set("objects", ([
		__DIR__"npc/yuanzhi" : 1,
		__DIR__"npc/yutong" : 1,
	]));

	set("cost", 0);
	setup();
	replace_program(ROOM);
}

