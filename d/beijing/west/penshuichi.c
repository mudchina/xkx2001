//Cracked by Roath
// Room: /d/beijing/west/penshuichi.c

inherit ROOM;

void create()
{
	set("short", "喷水池");
	set("long", @LONG
这是一个广场，正中有个水池，池中尾尾金鱼在悠闲的漫游。
水池中有块高达数丈的太湖石，数道水流从顶部向下流，行成一道
道小小的瀑布。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"baihuayuan",
  "south" : __DIR__"shibanlu2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
