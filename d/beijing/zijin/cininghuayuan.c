//Cracked by Roath
// Room: /d/beijing/zijincheng/cininghu.c

inherit ROOM;

void create()
{
	set("short", "慈宁花园");
	set("long", @LONG
这是一个大花园，有几个太监正在浇花。花的品种很多，每逢春
秋两季，百花齐放，煞是好看。旁边有一排花架。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"ciningmen",
  "east" : __DIR__"zaobanchu",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
