//Cracked by Roath
// Room: /d/mingjiao/shanlu20.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "山麓");
	set("long", @LONG
一连几个山头，高低相错，看去相隔不远，走去才知不近。好在途中
景色秀丽，留恋其中，不乐回返。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"shanlu19",
  "southup" : __DIR__"tiehanshan",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
