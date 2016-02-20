//Cracked by Roath
// Room: /d/beijing/kangqin/zhoulang8.c

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"xiaoyuan",
  "east" : __DIR__"houtang",
  "southwest" : __DIR__"zhoulang9",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
