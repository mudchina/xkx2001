//Cracked by Roath
// Room: /d/beijing/west/zhizhudian.c

inherit ROOM;

void create()
{
	set("short", "智珠殿");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"puandian",
  "east" : __DIR__"bridge",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
