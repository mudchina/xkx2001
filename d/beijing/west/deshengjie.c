//Cracked by Roath
// Room: /d/beijing/west/deshengjie.c

inherit ROOM;

void create()
{
	set("short", "得胜门大街");
	set("long", @LONG
这是繁华热闹的得胜门大街，大街街面宽阔，车水马龙，
川流不息，人群熙熙攘攘，来来往往。街边上耍枪买艺、百货
小吃，应有尽有，帝都风貌可见一斑。东面是一座古朴的庙宇，
香火缭绕，那就是天下学武之人所共同敬仰的武庙了。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"guloudajie",
  "east" : __DIR__"wumiao",
  "northwest" : __DIR__"deshengmen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
