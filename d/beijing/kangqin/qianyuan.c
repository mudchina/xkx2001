//Cracked by Roath
// Room: /d/beijing/kangqin/tingyuan.c

inherit ROOM;

void create()
{
	set("short", "前院");
	set("long", @LONG
这是王府的前院，一道影壁将院子分成两半。东西方各有一
间厢房，那是仆人们住的地方。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"zhongmen",
  "west" : __DIR__"xixiangfang",
  "north" : __DIR__"door",
  "east" : __DIR__"dongxiangfang",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
