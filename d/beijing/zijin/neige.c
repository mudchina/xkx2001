//Cracked by Roath
// Room: /d/beijing/zijincheng/neige.c

inherit ROOM;

void create()
{
	set("short", "内阁");
	set("long", @LONG
内阁大学士，学士们在此办事。房间里面的桌子上铺满了笔，墨，
纸，砚。阳光从外面射进来，照在墨汁上，令空气中充满了墨香和书香。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"wenhuadian",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
