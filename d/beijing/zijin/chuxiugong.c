//Cracked by Roath
// Room: /d/beijing/zijincheng/chuxiugong.c

inherit ROOM;

void create()
{
	set("short", "储秀宫");
	set("long", @LONG
这里原来是顺治最宠爱的妃子董鄂妃居住的地方。董鄂妃生病死后，
顺治也一直很忧郁，不久就驾崩了。现在无人居住。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"xianfugong",
  "south" : __DIR__"tihedian",
  "north" : __DIR__"lijingxuan",
  "east" : __DIR__"tongdao3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
