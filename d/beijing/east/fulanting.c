//Cracked by Roath
// Room: /d/beijing/east/fulanting.c

inherit ROOM;

void create()
{
	set("short", "富览亭");
	set("long", @LONG
这是五峰亭中的一座，四周景色秀丽，恬静宜人。亭子里有
一张石桌，几张石凳，供游人休息。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"shandao2",
  "southwest" : __DIR__"shandao5",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
