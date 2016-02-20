//Cracked by Roath
// Room: /d/beijing/west/zhengyangdajie.c

inherit ROOM;

void create()
{
	set("short", "正阳门外大街");
	set("long", @LONG
这是繁华热闹的正阳门外大街，大街街面宽阔，车水马龙
，川流不息，人群熙熙攘攘，来来往往。街边上耍枪买艺、百
货小吃，应有尽有，帝都风貌可见一斑。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"tianqiao2",
  "north" : __DIR__"zhengyangmen",
  "south" : __DIR__"shizilukou",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
