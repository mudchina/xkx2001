//Cracked by Roath
// Room: /d/beijing/east/dongzhidajie.c

inherit ROOM;

void create()
{
	set("short", "东直门大街");
	set("long", @LONG
这是繁华热闹的东直门大街，大街街面宽阔，车水马龙，
川流不息，人群熙熙攘攘，来来往往。街边上耍枪买艺、百货
小吃，应有尽有，帝都风貌可见一斑。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"dongzhidajie2",
  "east" : __DIR__"dongzhimen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
