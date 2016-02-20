//Cracked by Roath
// Room: /d/beijing/guloudajie_e.c

inherit ROOM;

void create()
{
	set("short", "鼓楼东大街");
	set("long", @LONG
这是繁华热闹的鼓楼东大街，大街街面宽阔，车水马龙，
川流不息，人群熙熙攘攘，来来往往。街边上耍枪买艺、百货
小吃，应有尽有，帝都风貌可见一斑。西面就是鼓楼。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"gulou",
  "east" : __DIR__"dongzhidajie",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
