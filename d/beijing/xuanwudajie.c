//Cracked by Roath
// Room: /d/beijing/xuanwudajie.c

inherit ROOM;

void create()
{
	set("short", "宣武门大街");
	set("long", @LONG
这是繁华热闹的宣武门大街，大街街面宽阔，车水马龙，川流不息，人群熙
熙攘攘，来来往往。街边上耍枪买艺、百货小吃，应有尽有，帝都风貌可见一斑。
LONG
	);
	set("exits", ([
		  "north" : __DIR__"xuanwumen",
		  "south" : __DIR__"caishikou",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");
	set("cost", 2);

	setup();
	replace_program(ROOM);
}
