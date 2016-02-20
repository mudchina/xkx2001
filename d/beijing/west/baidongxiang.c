//Cracked by Roath
// Room: /d/beijing/west/baidongxiang.c

inherit ROOM;

void create()
{
	set("short", "东厢房");
	set("long", @LONG
这是白家大宅的东厢房，里面打扫得纤尘不染，干净
得出奇。靠墙边立着一个大沉香木架，上面错落有致的摆
放着一些古董，从窗子望出去，可以看到前院。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"baiqianyuan",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
