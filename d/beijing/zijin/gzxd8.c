//Cracked by Roath
// Room: /d/beijing/zijincheng/gzxd8.c

inherit ROOM;

void create()
{
	set("short", "宫中小道");
	set("long", @LONG
这是宫殿之间的夹道，静静的，偶尔有几个侍卫或太监走过。小
鸟停在树枝，叽叽喳喳叫个不停。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"gzxd9",
  "west" : __DIR__"jingrengong",
  "east" : __DIR__"yanxigong",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
