//Cracked by Roath
// Room: /d/beijing/west/fuyoujie2.c

inherit ROOM;

void create()
{
	set("short", "府右街");
	set("long", @LONG
这是一条僻静的青石板街，路上只有潦潦落落几个行人，与京城
其它大街的热闹劲比起来是远远不及，在这里隐隐可以听到阜城门大
街上的喧哗声，青石板路向南一直延伸过去。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"fuchengmenjie",
  "south" : __DIR__"fuyoujie",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
