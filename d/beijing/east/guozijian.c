//Cracked by Roath
// Room: /d/beijing/east/guozijian.c

inherit ROOM;

void create()
{
	set("short", "国子监");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"zhongtianlou",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
