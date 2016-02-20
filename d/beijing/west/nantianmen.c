//Cracked by Roath
// Room: /d/beijing/west/nantianmen.c

inherit ROOM;

void create()
{
	set("short", "南天门");
	set("long", @LONG
这里是天坛的南大门，天坛有内外两重坛墙，坛墙南方
北圆，象征“天圆地方”。是皇帝祈祷五谷丰登的场所。这里
守卫不严，很容易溜进去。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"xiaohutong3",
  "north" : __DIR__"shibanlu5",
  "southwest" : __DIR__"xiaohutong2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
