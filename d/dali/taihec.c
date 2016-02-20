//Cracked by Roath
// Room: /d/dali/taihec.c

inherit ROOM;

void create()
{
	set("short", "太和城");
	set("long", @LONG
此城是乌夷族的治府，全城巷陌都以石垒成，高丈余，连绵数里不断。太和
不算大城，但人口为数并不少，地理上和军事上是大理城的北门户，历代大理王
朝都在此加固城池，派驻精兵。附近有一些乌夷部族聚居。此南是一片平原，下
十五里便达大理城。
LONG);
	set("objects", ([
		__DIR__"npc/dalishibing.c" : 2,
		__DIR__"npc/wujiang.c" : 1,
		]));
	set("exits", ([
		"north" : __DIR__"nanbei",
		"south" : __DIR__"gaten1",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
