//Cracked by Roath
// Room: /d/mingjiao/jiashan.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "假山");
	set("long", @LONG
穿过长廊，奇峰绝嶂累累乎墙外，人置其中，若处大山之麓，而截溪
断谷，私此数石者。穿深覆冈，因形布置，土石相间，颇得真趣。背阴处
隐刻诗云：
				换却花篱补石阑
				改园更比改诗难
				果能字字吟来稳
				小有亭台亦耐看
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"jiuqu",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
