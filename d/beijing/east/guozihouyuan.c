//Cracked by Roath
// Room: /d/beijing/east/guozihouyuan.c

inherit ROOM;

void create()
{
	set("short", "后院");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"guozihoutang",
  "north" : __DIR__"changshuge",
  "west" : __DIR__"shufang1",
  "east" : __DIR__"shufang2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
