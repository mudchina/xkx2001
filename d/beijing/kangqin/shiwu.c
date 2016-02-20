//Cracked by Roath
// Room: /d/beijing/kangqin/shiwu.c

inherit ROOM;

void create()
{
	set("short", "石屋");
	set("long", @LONG
这是一座孤零零的石屋，里面甚是阴暗。门口有几个
侍卫在来回巡逻。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"garden",
  "south" : __DIR__"xiaotang",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
