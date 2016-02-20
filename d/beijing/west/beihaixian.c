//Cracked by Roath
// Room: /d/beijing/west/beihaixian.c

inherit ROOM;

void create()
{
	set("short", "北海西岸");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"fucuiting",
  "southwest" : __DIR__"beihaiximen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
