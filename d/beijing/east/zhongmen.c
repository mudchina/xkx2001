//Cracked by Roath
// Room: /d/beijing/east/zhongmen.c

inherit ROOM;

void create()
{
	set("short", "中门");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"paomachang",
  "south" : __DIR__"qianyuan",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
