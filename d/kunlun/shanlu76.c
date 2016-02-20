//Cracked by Roath
// Room: /d/mingjiao/shanlu76.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
众多明教弟子于此经过，成群结队，喧哗亦大。左边是一片密松林，
不时传来一阵阵猿啼。右边是悬崖陡壁，万一失足，无人能救。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southdown" : __DIR__"shenhuo",
  "west" : __DIR__"milin36",
  "enter" : __DIR__"ldating",
]));
	set("no_clean_up", 0);
	set("cost", 2);

	setup();
	replace_program(ROOM);
}
