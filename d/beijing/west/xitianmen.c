//Cracked by Roath
// Room: /d/beijing/west/xitianmen.c

inherit ROOM;

void create()
{
	set("short", "西天门");
	set("long", @LONG
这里是天坛的西大门，天坛有内外两重坛墙，坛墙南方北
圆，象征“天圆地方”。是皇帝祈祷五谷丰登的场所。这里守
卫不严，很容易溜进去。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"baihuayuan",
  "west" : __DIR__"shizilukou",
  "east" : __DIR__"shibanlu1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
