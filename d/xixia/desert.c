//Cracked by Roath
// Room: /d/xixia/desert.c

inherit ROOM;

void create()
{
	set("short", "沙漠");
	set("long", @LONG
这是一片没边际的沙漠，到处是近百米高的巨大沙丘。你一走进来就
仿佛迷了路。
LONG
	);
	set("cost", 2);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"desert",
  "north" : __DIR__"jingyuan",
  "south" : __DIR__"desert1",
  "east" : __DIR__"desert",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
