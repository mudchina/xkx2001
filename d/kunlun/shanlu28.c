//Cracked by Roath
// Room: /d/mingjiao/shanlu28.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
青石路边开满山菊。黄黄一片，随风回动。对面时时走过几个明教弟
子，有的怀里抱着几把刀剑。朝西边而去。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"jxiaochang",
  "north" : __DIR__"wuqiku",
  "enter" : __DIR__"jneiting",
  "south" : __DIR__"jinlianchang",
]));
	set("no_clean_up", 0);
	set("cost", 2);

	setup();
	replace_program(ROOM);
}
