//Cracked by Roath
// Room: /d/beijing/west/hubianxiaodao2.c

inherit ROOM;

void create()
{
	set("short", "湖边小道");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"zhonghaidongan",
  "west" : __DIR__"zhonghaibeian",
  "east" : __DIR__"shulin1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
