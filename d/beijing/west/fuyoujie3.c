//Cracked by Roath
// Room: /d/beijing/west/fuyoujie3.c

inherit ROOM;

void create()
{
	set("short", "府右街");
	set("long", @LONG
这是一条僻静的青石板街，路上只有潦潦落落几个行人，与其它
大街的热闹劲比起来是远远不及。向东走是一个大湖，南边就是紫禁
城了，可以远远瞅见太和殿的殿顶。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"fuyoujie",
  "south" : "/d/beijing/zijin/xichangan",
  "east" : __DIR__"nanhaixian",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
