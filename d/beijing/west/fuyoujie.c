//Cracked by Roath
// Room: /d/beijing/west/fuyoujie.c

inherit ROOM;

void create()
{
	set("short", "府右街");
	set("long", @LONG
这是一条僻静的青石板街，路上只有潦潦落落几个行人，与其它
大街的热闹劲比起来是远远不及。向东走是一个大湖，西边是一条胡
同，隐约传来狗吠之声。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"lingjing",
  "north" : __DIR__"fuyoujie2",
  "south" : __DIR__"fuyoujie3",
  "east" : __DIR__"zhonghaixian",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
