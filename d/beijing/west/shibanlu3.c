//Cracked by Roath
// Room: /d/beijing/west/shibanlu3.c

inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"danbiqiao",
  "east" : __DIR__"dongtianmen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
