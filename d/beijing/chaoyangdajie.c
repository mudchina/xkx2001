//Cracked by Roath
// Room: /d/beijing/chaoyangdajie.c

inherit ROOM;

void fix_exits_for_night(int is_night)
{
    if (is_night) {
	set("exits", ([ 
	  "west" : __DIR__"jingshan",
	  "south": __DIR__"wangfudajie",
	  "north" : __DIR__"dongzhidajie",
	]));
    } else {
	set("exits", ([ 
	  "west" : __DIR__"jingshan",
	  "south": __DIR__"wangfudajie",
	  "east" : __DIR__"chaoyangmen",
	  "north" : __DIR__"dongzhidajie",
	]));
    }
}

void create()
{
	set("short", "朝阳门大街");
	set("long", @LONG
这是繁华热闹的朝阳门大街，大街街面宽阔，车水马龙，川流不息，人群熙
熙攘攘，来来往往。街边上耍枪买艺、百货小吃，应有尽有，帝都风貌可见一斑。
LONG
	);
	fix_exits_for_night(0);
	set("outdoors", "beijing");
	set("cost", 2);
	set("no_clean_up", 0);

	setup();
}


