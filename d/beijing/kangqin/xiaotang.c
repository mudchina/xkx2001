//Cracked by Roath
// Room: /d/beijing/kangqin/xiaotang.c

inherit ROOM;

void create()
{
	set("short", "小堂");
	set("long", @LONG
这里既阴暗又潮湿，行廊边搭了一个灶台，里面煮着
白菜猪肉。前面是一间牢房，从那里不时传来镣铐拖
地的声音。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"shiwu",
  "south" : __DIR__"laofang",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
