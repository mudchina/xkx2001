//Cracked by Roath
// Room: /d/beijing/west/zhonghaidongan.c

inherit ROOM;

void create()
{
	set("short", "中海东岸");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"hubianxiaodao4",
  "north" : __DIR__"hubianxiaodao2",
  "east" : __DIR__"shulin1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
