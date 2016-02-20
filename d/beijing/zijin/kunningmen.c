//Cracked by Roath
// Room: /d/beijing/zijincheng/kunningmen.c

inherit ROOM;

void create()
{
	set("short", "坤宁门");
	set("long", @LONG
这里向南是坤宁宫,向北是御花园.
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"yuhuayuan",
  "south" : __DIR__"kunninggong",
  "west" : __DIR__"tongdao3",
  "east" : __DIR__"tongdao6",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
