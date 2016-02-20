//Cracked by Roath
// Room: /d/beijing/zijincheng/xianfugong.c

inherit ROOM;

void create()
{
	set("short", "咸福宫");
	set("long", @LONG
这是一间空房间，不知道是用来做什么的。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"tongdaotang",
  "east" : __DIR__"chuxiugong",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
