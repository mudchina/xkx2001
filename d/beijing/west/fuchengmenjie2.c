//Cracked by Roath
// Room: /d/beijing/west/fuchengmenjie2.c

inherit ROOM;

void create()
{
	set("short", "阜成门大街");
	set("long", @LONG
这是繁华热闹的阜成门大街，大街街面宽阔，车水马龙，
川流不息，人群熙熙攘攘，来来往往。街边上耍枪买艺、百货
小吃，应有尽有，帝都风貌可见一斑。西边就是阜成门。
LONG
	);
	set("exits", ([ /* sizeof() == 5 */
  "southeast" : __DIR__"lingjing",
  "south" : __DIR__"xuanwudajie",
  "west" : __DIR__"fuchengmen",
  "north" : __DIR__"baozhu",
  "east" : __DIR__"fuchengmenjie",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
