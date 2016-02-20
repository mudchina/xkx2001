//Cracked by Roath
// Room: /d/beijing/west/yonganmen.c

inherit ROOM;

void create()
{
	set("short", "永安门");
	set("long", @LONG
这是北京城外城五大城门中南面的城门，这里的城墙略显破旧，不及内城
光鲜，守门的官兵通常由骁骑营侍卫率领。城门边上是一张告示 (gaoshi)，
两边的土路通向左安门和右安门。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "east"  : __DIR__"tulu_yaza1",
  "west"  : __DIR__"tulu_yaya1",
  "north" : __DIR__"shizilukou",
  "south" : __DIR__"dadao_yas1",
]));

	set("objects", ([
	__DIR__"../npc/bj_bing":2,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
