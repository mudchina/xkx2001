//Cracked by Roath
// Room: /d/xiangyang/guangdeshi.c

inherit ROOM;

void create()
{
	set("short", "广德寺");
	set("long", @LONG
广德寺原名云居寺，建於唐贞观年间。四周的亭院皆为砖石仿木结构，已颇
为破旧。你一进来，映入眼眶的是面前显眼的五座塔林。见底层塔座为八方形
，四面各有一石砌券门，称“八方四门”，正门上方石额刻“多宝佛塔”四字。
塔旁有银杏树三株，其中一棵(tree)树粗壮，枝叶茂盛。
LONG
	);
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"qilidian",
  "enter" : __DIR__"duofota",
  "west" : __DIR__"milin",
]));
set("item_desc", ([
		"tree" : "传说，广德寺一名叫海周的当家老和尚，一日起床後，发现这棵树落死亡，要
死当家人。他便要离寺，徒弟不让。他说，树活之日我复归。他走後，弟子们整
日抱树痛哭，泪水湿透树根，翌年春，树又发芽，海周归寺。\n",
	]));
	setup();
	replace_program(ROOM);
}
