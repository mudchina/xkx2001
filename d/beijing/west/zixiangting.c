//Cracked by Roath
// Room: /d/beijing/west/zixiangting.c

inherit ROOM;

void create()
{
	set("short", "滋香亭");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"beihaixian2",
  "southwest" : __DIR__"chengxiangting",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
