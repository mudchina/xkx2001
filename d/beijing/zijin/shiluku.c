//Cracked by Roath
// Room: /d/beijing/zijincheng/shiluku.c

inherit ROOM;

void create()
{
	set("short", "实录库");
	set("long", @LONG
这是一间空房间，不知道是用来做什么的。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"hongbenku",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
