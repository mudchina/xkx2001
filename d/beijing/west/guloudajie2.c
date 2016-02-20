//Cracked by Roath
// Room: /d/beijing/west/guloudajie2.c

inherit ROOM;

void create()
{
	set("short", "鼓楼大街");
	set("long", @LONG
这是繁华热闹的鼓楼大街，大街街面宽阔，车水马龙，川
流不息，人群熙熙攘攘，来来往往。街边上耍枪买艺、百货小
吃，应有尽有，帝都风貌可见一斑。东面就是京城的鼓楼。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"xizhidajie2",
  "east" : __DIR__"gulou",
  "northwest" : __DIR__"guloudajie",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
