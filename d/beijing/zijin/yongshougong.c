//Cracked by Roath
// Room: /d/beijing/zijincheng/yongshougong.c

inherit ROOM;

void create()
{
	set("short", "永寿宫");
	set("long", @LONG
这是明清两代后妃们居住的地方.
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"yangxindian",
  "west" : __DIR__"taijidian",
  "east" : __DIR__"tongdao1",
]));
	set("no_clean_up", 0);
	set("exit", "e");

	setup();
	replace_program(ROOM);
}
