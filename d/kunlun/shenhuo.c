//Cracked by Roath
// Room: /d/mingjiao/shenhuo.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "神火峰");
	set("long", @LONG
此峰高耸入云，遍地坚石，承赤色。云布其下，聚而成海。云日交潜
之时，天亦染红，与此峰相互生晖。人置峰顶，如身陷火海。远处看去更
是如此。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"shanlu76",
  "southdown" : __DIR__"shangang",
]));
	set("no_clean_up", 0);
	set("cost", 2);

	setup();
	replace_program(ROOM);
}
