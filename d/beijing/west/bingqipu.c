//Cracked by Roath
// Room: /d/beijing/west/bingqipu.c

inherit ROOM;

void create()
{
	set("short", "兵器铺");
	set("long", @LONG
这是一间京城里常见的兵器铺，当今天下太平，兵器铺
的生意也清淡了不少，所以兵器铺也兼营些日常铁器，不过
京城天子脚下，这里东西质量倒蛮不错。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"tianqiao4",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
