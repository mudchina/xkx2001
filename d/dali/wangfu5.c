//Cracked by Roath
// Room: /d/dali/wangfu5.c

inherit ROOM;

void create()
{
	set("short", "喷水池");
	set("long", @LONG
这是一个广场，正中有个水池，池中尾尾金鱼在悠闲的漫游。水池中有块高
达数丈的太湖石，数道水流从顶部向下流，行成一道道小小的瀑布。
LONG);
	set("exits", ([
		"east" : __DIR__"garden1.c",
		"west" : __DIR__"wangfu3",
		]));
	set("cost", 1);
	set("wangfu", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
