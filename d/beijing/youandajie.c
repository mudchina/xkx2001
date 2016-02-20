//Cracked by Roath
// Room: /d/beijing/youandajie.c

inherit ROOM;

void fix_exits_for_night(int is_night);

void create()
{
	set("short", "右安门大街");
	set("long", @LONG
这是繁华热闹的右安门大街，大街街面宽阔，车水马龙，川流不息，人群熙
熙攘攘，来来往往。街边上耍枪买艺、百货小吃，应有尽有，帝都风貌可见一斑。
LONG
	);
	fix_exits_for_night(0);
	set("no_clean_up", 0);
	set("cost", 2);

	setup();
	replace_program(ROOM);
}

void fix_exits_for_night(int is_night)
{
    object me = this_object();
    if (is_night) {
	me->set("exits", ([ /* sizeof() == 3 */
	      "north" : __DIR__"caishikou",
	]));
    }else{
	me->set("exits", ([ /* sizeof() == 4 */
	      "north" : __DIR__"caishikou",
	      "south" : __DIR__"youanmen",
	]));
    }
}
