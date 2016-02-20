//Cracked by Roath
// Room: /d/beijing/kangqin/laofang.c

inherit ROOM;

void create()
{
	set("short", "牢房");
	set("long", @LONG
这是一间牢房。铁门极厚，门上的小窗装着鸭子儿粗细
的铁条，显然是怕犯人冲出来。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"xiaotang",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
