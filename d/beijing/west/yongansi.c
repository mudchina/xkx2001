//Cracked by Roath
// Room: /d/beijing/west/yongansi.c

inherit ROOM;

void create()
{
	set("short", "永安寺");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"yonganqiao",
  "north" : __DIR__"puandian",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
