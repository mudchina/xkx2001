//Cracked by Roath
// Room: /d/beijing/west/puandian.c

inherit ROOM;

void create()
{
	set("short", "普安殿");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"yongansi",
  "north" : __DIR__"baita",
  "east" : __DIR__"zhizhudian",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
