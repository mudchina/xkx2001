//Cracked by Roath
// Room: /d/beijing/west/fuchengmenjie.c

inherit ROOM;

void create()
{
	set("short", "阜成门大街");
	set("long", @LONG
这是繁华热闹的阜成门外大街，大街街面宽阔，车水马龙
，川流不息，人群熙熙攘攘，来来往往。街边上耍枪买艺、百
货小吃，应有尽有，帝都风貌可见一斑。东边可以看见北海。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"fuyoujie2",
  "west" : __DIR__"fuchengmenjie2",
  "east" : __DIR__"beihaiximen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
