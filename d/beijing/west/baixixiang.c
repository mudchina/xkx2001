//Cracked by Roath
// Room: /d/beijing/west/baixixiang.c

inherit ROOM;

void create()
{
	set("short", "西厢房");
	set("long", @LONG
这是白家大宅的西厢房，里面打扫得纤尘不染，干净
得出奇。靠墙边立着一个大沉香木架，上面错落有致的摆
放着一些古董，从窗子望出去，可以看到前院。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"baiqianyuan",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
