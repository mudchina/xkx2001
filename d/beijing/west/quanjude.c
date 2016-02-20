//Cracked by Roath
// Room: /d/beijing/west/quanjude.c

inherit ROOM;

void create()
{
	set("short", "全聚德");
	set("long", @LONG
这是北京城鼎鼎大名的全聚德烤鸭店，但凡外地人来北京莫不要
到这著名的全聚德烤鸭店来尝个鲜儿，就算老北京提起全聚德也是翘
大姆指的。这里常年宾客盈门，店面里不少是等座的客人，楼上是雅
座，价格比楼下也高得多。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"quanjude2",
  "south" : __DIR__"tianqiao1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
