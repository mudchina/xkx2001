//Cracked by Roath
// Room: /d/beijing/zijincheng/tongdaotang.c

inherit ROOM;

void create()
{
	set("short", "同道堂");
	set("long", @LONG
这是一间空房间，不知道是用来做什么的。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"xianfugong",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
