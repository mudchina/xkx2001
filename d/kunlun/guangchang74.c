//Cracked by Roath
// Room: /d/mingjiao/guangchang74.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "广场");
	set("long", @LONG
此处是一个小广场，只见一队队教众来来去去，身着各种服色，有的
携带刀，枪，棍，杖等兵器，个个身姿矫健，神态庄重。广场不大，贯通
了南北两边的风字、雷字门大厅。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"shmen",
  "south" : __DIR__"lei",
  "north" : __DIR__"feng",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
