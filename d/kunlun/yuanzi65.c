//Cracked by Roath
// Room: /d/mingjiao/yuanzi65.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "院子");
	set("long", @LONG
院子中青石小道，遍满奇花异草，怪干希枝，暗香浮动，月影漫情，
时闻虫草风律。虽无山水之丽，然居清闭阁，幽回尘绝，兰掬之属，蔚然
深秀。但见西厢房的窗子中透出灯火之光。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"xixiang",
  "south" : __DIR__"ceting64",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
