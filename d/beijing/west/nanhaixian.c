//Cracked by Roath
// Room: /d/beijing/west/nanhaixian.c

inherit ROOM;

void create()
{
	set("short", "南海西岸");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"fuyoujie3",
  "north" : __DIR__"hubianxiaodao3",
  "south" : __DIR__"hubianxiaodao5",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
