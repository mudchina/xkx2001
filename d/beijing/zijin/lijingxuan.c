//Cracked by Roath
// Room: /d/beijing/zijincheng/lijingxuan.c

inherit ROOM;

void create()
{
	set("short", "丽景轩");
	set("long", @LONG
这是一间华丽别致的房间。但是不经常有人来，只有几个太监在
打扫卫生。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"chuxiugong",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
