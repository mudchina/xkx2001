//Cracked by Roath
// Room: /d/beijing/west/guangandajie.c

inherit ROOM;

void create()
{
	set("short", "广安门大街");
	set("long", @LONG
这是繁华热闹的广安门大街，大街街面宽阔，车水马龙，
川流不息，人群熙熙攘攘，来来往往。街边上耍枪买艺、百货
小吃，应有尽有，帝都风貌可见一斑。东边是菜市口。
LONG
	);
	set("exits", ([ /* sizeof() == 5 */
  "southeast" : __DIR__"yizhan",
  "west" : __DIR__"guanganmen",
  "south" : __DIR__"youandajie",
  "east" : __DIR__"caishikou",
  "northwest" : __DIR__"xibianmen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
