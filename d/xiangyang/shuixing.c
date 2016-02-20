//Cracked by Roath
// Room: /d/xiangyang/shuixingtai.c

inherit ROOM;

void create()
{
	set("short", "水星台");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"wangcg",
  "westdown" : __DIR__"migonglu",
  "east" : __DIR__"sshuiguan",
]));

	setup();
	replace_program(ROOM);
}
