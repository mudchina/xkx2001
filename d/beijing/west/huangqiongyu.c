//Cracked by Roath
// Room: /d/beijing/west/huangqiongyu.c

inherit ROOM;

void create()
{
	set("short", "皇穹宇");
	set("long", @LONG
这是存放祭祀神牌位的地方。外面有一道圆形磨砖对缝的围墙，是著名的
“回音壁”。南面大厅入口处放着三块石头。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"huanqiu",
  "north" : __DIR__"danbiqiao",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
