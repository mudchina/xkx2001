//Cracked by Roath
// Room: /d/beijing/zijincheng/pibenchu.c

inherit ROOM;

void create()
{
	set("short", "批本处");
	set("long", @LONG
凡是内阁经手的本章都经批本处进呈给皇帝,皇帝阅批后,再由
批本处交内阁.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"maoqindian",
  "south" : __DIR__"yuehuamen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
