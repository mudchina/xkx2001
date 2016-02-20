//Cracked by Roath
// Room: /d/beijing/zijincheng/jingrengong.c

inherit ROOM;

void create()
{
	set("short", "景仁宫");
	set("long", @LONG
东六宫之一，这是明清两代后妃们居住的地方。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"tongdao4",
  "south" : __DIR__"chengsudian",
  "east" : __DIR__"gzxd8",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
