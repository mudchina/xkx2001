//Cracked by Roath
// Room: /d/mingjiao/jiuqu.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "九曲廊");
	set("long", @LONG
自廊中望去，此处覆坚土为台，聚奇石为山，环斗水为池。岸上绿柳
成阴，花繁朵絮，蝉鸣鹤啼。再看水中，荷碧莲红，虾游鱼戏。于中体会
物情，留连光景，小园小山足可神游。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"ceting67",
  "northeast" : __DIR__"jiashan",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
