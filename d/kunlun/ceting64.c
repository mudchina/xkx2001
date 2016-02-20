//Cracked by Roath
// Room: /d/mingjiao/ceting64.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "侧厅");
	set("long", @LONG
侧厅并非太大，然所置甚为清素。正中一白玉瓷桌，环有四个汉白石
座。墨荷翠竹琳琅于壁，南墙下为一小案，上有小山假景。北面门外是庭
院，花木中亦有几棵茶。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"yuanzi65",
  "east" : __DIR__"shting",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
