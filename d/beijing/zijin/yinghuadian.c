//Cracked by Roath
// Room: /d/beijing/zijincheng/yinghuadian.c

inherit ROOM;

void create()
{
	set("short", "英华殿");
	set("long", @LONG
   无资料.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"shouangong",
  "north" : __DIR__"tongdao8",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
