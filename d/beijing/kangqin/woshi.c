//Cracked by Roath
// Room: /d/beijing/kangqin/woshi.c

inherit ROOM;

void create()
{
	set("short", "王爷卧室");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"neishi",
  "north" : __DIR__"garden2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
