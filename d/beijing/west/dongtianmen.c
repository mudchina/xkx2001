//Cracked by Roath
// Room: /d/beijing/west/dongtianmen.c

inherit ROOM;

void create()
{
	set("short", "东天门");
	set("long", @LONG
这里是天坛的东大门，天坛有内外两重坛墙，坛墙南方
北圆，象征“天圆地方”。是皇帝祈祷五谷丰登的场所。这里
守卫不严，很容易溜进去。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"shibanlu3",
  "east" : "/d/beijing/east/guangqudajie",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
