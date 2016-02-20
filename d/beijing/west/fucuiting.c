//Cracked by Roath
// Room: /d/beijing/west/fucuiting.c

inherit ROOM;

void create()
{
	set("short", "浮翠亭");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"yongruiting",
  "south" : __DIR__"beihaixian",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
