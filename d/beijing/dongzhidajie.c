//Cracked by Roath
// Room: /d/beijing/dongzhidajie.c

inherit ROOM;

void fix_exits_for_night(int is_night)
{
    if (is_night) {
	set("exits", ([ /* sizeof() == 2 */
	  "west" : __DIR__"guloudajie_e",
	  "south" : __DIR__"chaoyangdajie",
	  "north" : __DIR__"shiweiying",
	]));
    } else {
	set("exits", ([ /* sizeof() == 2 */
	  "west" : __DIR__"guloudajie_e",
	  "east" : __DIR__"dongzhimen",
	  "south" : __DIR__"chaoyangdajie",
	  "north" : __DIR__"shiweiying",
	]));
    }
}

void create()
{
	set("short", "东直门大街");
	set("long", @LONG
这是繁华热闹的东直门大街，大街街面宽阔，车水马龙，
川流不息，人群熙熙攘攘，来来往往。街边上耍枪买艺、百货
小吃，应有尽有，帝都风貌可见一斑。
LONG
	);
	fix_exits_for_night(0);
	set("outdoors", "beijing");

	set("no_clean_up", 0);
	set("outdoors", "beijing");
	set("cost", 2);

	setup();
}
