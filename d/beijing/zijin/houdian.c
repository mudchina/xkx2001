//Cracked by Roath
// Room: /d/beijing/zijincheng/houdian.c

inherit ROOM;

void create()
{
	set("short", "ºóµî");
	set("long", @LONG
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"shouangong",
  "south" : __DIR__"shoukanggong",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
