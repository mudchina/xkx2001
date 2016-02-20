//Cracked by Roath
// Room: /d/beijing/zijincheng/taijidian.c

inherit ROOM;

void create()
{
	set("short", "太极殿");
	set("long", @LONG
这是明清两代后妃们居住的地方.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"tiyuandian",
  "east" : __DIR__"yongshougong",
]));
	set("no_clean_up", 0);
	set("exit", "e");

	setup();
	replace_program(ROOM);
}
