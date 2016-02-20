//Cracked by Roath
// Room: /d/beijing/east/wangfudajie.c

inherit ROOM;

void create()
{
	set("short", "王府大街");
	set("long", @LONG
这是繁华热闹的王府大街，大街街面宽阔，车水马龙，川
流不息，人群熙熙攘攘，来来往往。街边上耍枪买艺、百货小
吃，应有尽有，帝都风貌可见一斑。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"wangfudajie2",
  "north" : __DIR__"zhaoyangdajie2",
  "east" : __DIR__"qianju",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
