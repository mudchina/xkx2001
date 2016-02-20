//Cracked by Roath
// Room: /d/beijing/west/guloudajie.c

inherit ROOM;

void create()
{
	set("short", "鼓楼大街");
	set("long", @LONG
这是繁华热闹的鼓楼大街大街，大街街面宽阔，车水马龙，
川流不息，人群熙熙攘攘，来来往往。街边上耍枪买艺、百货
小吃，应有尽有，帝都风貌可见一斑。东面就是钟楼。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"guloudajie2",
  "west" : __DIR__"yamen",
  "north" : __DIR__"deshengjie",
  "east" : __DIR__"zhonglou",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
