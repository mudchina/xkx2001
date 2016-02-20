//Cracked by Roath
// Room: /d/beijing/west/youandajie.c

inherit ROOM;

void create()
{
	set("short", "右安门大街");
	set("long", @LONG
这是繁华热闹的右安门大街，大街街面宽阔，车水马龙，
川流不息，人群熙熙攘攘，来来往往。街边上耍枪买艺、百货
小吃，应有尽有，帝都风貌可见一斑。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"guangandajie",
  "south" : __DIR__"youanmen",
  "east" : __DIR__"tianshuijing",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
