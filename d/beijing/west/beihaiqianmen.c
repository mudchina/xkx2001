//Cracked by Roath
// Room: /d/beijing/west/beihaiqianmen.c

inherit ROOM;

void create()
{
	set("short", "北海前门");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"zhonghaibeian",
  "northwest" : __DIR__"chengguangdian",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
