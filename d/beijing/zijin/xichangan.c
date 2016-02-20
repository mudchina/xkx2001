//Cracked by Roath
// Room: /d/beijing/taihe/xichangan.c

inherit ROOM;

void create()
{
	set("short", "西长安街");
	set("long", @LONG
这是北京城最宽的大街，可供四五匹马并排奔驰。可能是靠近皇
宫的原因，这里行人并不多，但经常可以看到一顶顶大轿子经过。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : "/d/beijing/west/xidan",
  "north" : "/d/beijing/west/fuyoujie3",
  "east" : __DIR__"tianansquare",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
