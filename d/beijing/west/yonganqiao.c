//Cracked by Roath
// Room: /d/beijing/west/yonganqiao.c

inherit ROOM;

void create()
{
	set("short", "永安桥");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"chengguangdian",
  "north" : __DIR__"yongansi",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
