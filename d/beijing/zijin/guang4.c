//Cracked by Roath
// Room: /d/beijing/zijincheng/guang4.c

inherit ROOM;

void create()
{
	set("short", "空旷广场");
	set("long", @LONG
这是空旷一个的广场，便于练习可跑马射箭。
清代武士殿试在此演示，皇帝便在南边的箭
亭阅技。由此往东是一排平房。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"jingyunmen",
  "north" : __DIR__"fengxiandian",
  "south" : __DIR__"jianting",
  "east" : __DIR__"ningshoumen",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
