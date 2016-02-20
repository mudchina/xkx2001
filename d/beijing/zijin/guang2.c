//Cracked by Roath
// Room: /d/beijing/zijincheng/guang2.c

inherit ROOM;

void create()
{
	set("short", "内金水桥");
	set("long", @LONG
桥白如云，水蓝如天，桥影在水中波动，宛若天上楼台宫阙。每
到早中晚三时，从熙和门，协和门涌出一队队的御林军和侍卫去换班。
LONG
	);
	set("exits", ([ /* sizeof() == 6 */
  "northeast" : __DIR__"zhaodemen",
  "west" : __DIR__"xihemen",
  "south" : __DIR__"wumen",
  "north" : __DIR__"taihemen",
  "east" : __DIR__"xiehemen",
  "northwest" : __DIR__"zhendumen",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
