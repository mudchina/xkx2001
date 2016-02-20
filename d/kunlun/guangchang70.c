//Cracked by Roath
// Room: /d/mingjiao/guangchang70.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "广场");
	set("long", @LONG
此处是一小广场，但见一队队教众来来去去，身着各种服色，有的携
带刀，枪，棍，杖等兵器，个个身姿矫健，神态庄重。北面是天字门大厅，
南方是地字门。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"di",
  "north" : __DIR__"tian",
  "east" : __DIR__"shmen",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
