//Cracked by Roath
// Room: /d/beijing/zijincheng/tiyuandian.c

inherit ROOM;

void create()
{
	set("short", "体元殿");
	set("long", @LONG
与该殿后檐相连的戏台即长春戏台,慈禧太后五十寿辰时,同宫内
的妃嫔及命妇每天在此看戏,长达半月之久.

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"changchungong",
  "south" : __DIR__"taijidian",
]));
	set("no_clean_up", 0);
	set("exit", "e");

	setup();
	replace_program(ROOM);
}
