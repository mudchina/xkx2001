//Cracked by Roath
// Room: /d/beijing/taihe/dongchangan.c

inherit ROOM;

void create()
{
	set("short", "东长安街");
	set("long", @LONG
这是北京城最宽的大街，可供四五匹马并排奔驰。可能是
靠近皇宫的原因，这里行人并不多，但经常可以看到一顶顶大
轿子经过。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : "/d/beijing/east/wangfudajie3",
  "west" : __DIR__"tianansquare",
  "east" : "/d/beijing/east/dongchangan2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
