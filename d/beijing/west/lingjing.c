//Cracked by Roath
// Room: /d/beijing/west/lingjing.c

inherit ROOM;

void create()
{
	set("short", "灵境胡同");
	set("long", @LONG
这是一条十分宽阔的胡同，但却没什么普通百姓来往。前面有
一扇朱漆大门，门口有一对石狮子，守卫相当森严，显然是官宦人
家。西南面是繁华的宣武大街。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : "/d/beijing/kangqin/door",
  "east" : __DIR__"fuyoujie",
  "southwest" : __DIR__"xuanwudajie",
  "northwest" : __DIR__"fuchengmenjie2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
