//Cracked by Roath
// Room: /d/xiangyang/jzjie1.c

inherit ROOM;

void create()
{
	set("short", "荆州街");
	set("long", @LONG
这是襄阳城中最繁华的荆州街。四周熙熙攘攘，小贩叫卖声与讨价还价声
此起彼伏。人群丛中，依稀可以见到东边是一间大客店。西北不远，那便是闻名
天下的岳阳楼，闻得鱼肉菜香阵阵传来，不由得食指大动。
LONG
	);
	set("no_clean_up", 0);
	set("coordinates", ([ "x" : 3, "y" : 2 ]) );
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"jzjie2",
  "south" : __DIR__"dongjie2",
  "east" : __DIR__"kedian",
  "northwest" : __DIR__"yueyang",
]));
	set("outdoors", "xiangyang");

	setup();
	replace_program(ROOM);
}
