//Cracked by Roath
// Room: /d/beijing/zijincheng/xiaodao2.c

inherit ROOM;

void create()
{
	set("short", "宫中小道");
	set("long", @LONG
这是宫殿之间的夹道，静静的，偶尔有几个侍卫或太监走过。小
鸟停在树枝，叽叽喳喳叫个不停。西边的台阶可以通往中和殿.
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"houzuomen",
  "south" : __DIR__"zhongzuomen",
  "west" : __DIR__"zhonghedian",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
