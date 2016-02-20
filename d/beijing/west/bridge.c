//Cracked by Roath
// Room: /d/beijing/west/bridge.c

inherit ROOM;

void create()
{
	set("short", "陟山桥");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"hubianxiaodao7",
  "west" : __DIR__"zhizhudian",
  "north" : __DIR__"beihaidongan",
  "east" : "/d/beijing/east/xiaojing1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
