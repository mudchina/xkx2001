//Cracked by Roath
// Room: /d/beijing/west/beitianmen.c

inherit ROOM;

void create()
{
	set("short", "北天门");
	set("long", @LONG
这里是天坛的北大门，天坛有内外两重坛墙，坛墙南方
北圆，象征“天圆地方”。是皇帝祈祷五谷丰登的场所。这里
守卫不严，很容易溜进去。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"xiaohutong1",
  "south" : __DIR__"shibanlu4",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
