//Cracked by Roath
inherit ROOM;

void create()
{
	set("short", "宫中小道");
	set("long",  @LONG
这是宫殿之间的夹道，静静的，偶尔有几个侍卫或太监走过。
小鸟停在树枝，叽叽喳喳叫个不停。
LONG
	);

	set("outdoors","beijing");
	set("exits", ([
		"north" : __DIR__"gzxd3",
		"south" : __DIR__"wenyuange",
	]));

	setup();
	replace_program(ROOM);
}