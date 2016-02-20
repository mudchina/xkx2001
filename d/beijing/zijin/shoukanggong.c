//Cracked by Roath
// Room: /d/beijing/zijincheng/shoukang.c

inherit ROOM;

void create()
{
	set("short", "ÊÙ¿µ¹¬");
	set("long", @LONG
    ÎÞ×ÊÁÏ.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"houdian",
  "east" : __DIR__"cininggong",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
