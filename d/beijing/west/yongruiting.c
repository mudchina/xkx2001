//Cracked by Roath
// Room: /d/beijing/west/yongruiting.c

inherit ROOM;

void create()
{
	set("short", "涌瑞亭");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"longzheting",
  "southwest" : __DIR__"fucuiting",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
