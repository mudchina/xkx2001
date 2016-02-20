//Cracked by Roath
// Room: /d/beijing/wangfudajie.c

inherit ROOM;

void create()
{
	set("short", "王府大街");
	set("long", @LONG
这是繁华热闹的王府大街，大街街面宽阔，车水马龙，川流不息，人群熙熙
攘攘，来来往往。街边上耍枪买艺、百货小吃，应有尽有，帝都风貌可见一斑。
街东便是京城里招牌最老的镖局—武胜镖局。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
                "south" : __DIR__"chongwenmen",
		"north" : __DIR__"chaoyangdajie",
		"east"  : __DIR__"wusheng",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");
	set("cost", 2);

	setup();
	replace_program(ROOM);
}
