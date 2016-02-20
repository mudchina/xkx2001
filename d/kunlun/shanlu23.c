//Cracked by Roath
// Room: /d/mingjiao/shanlu23.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "小山路");
	set("long", @LONG
路边渐渐荒秃，花草越来越淡。前面望去，一堆堆乱石，杂错无章，
人际全无。道路也坎坷难行。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"tiekuang",
  "northwest" : __DIR__"tiehanshan",
]));
	set("no_clean_up", 0);
	set("cost", 2);

	setup();
	replace_program(ROOM);
}
