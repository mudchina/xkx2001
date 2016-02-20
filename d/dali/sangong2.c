//Cracked by Roath
// Room: /d/dali/sangong2.c

inherit ROOM;

void create()
{
	set("short", "司马堂");
	set("long", @LONG
这间大堂宽敞明亮，两壁各有一行兵器架，刀枪剑戟皆全，书案之后更有宝
剑横于架上，堂中虎皮熊皮铺地，一望可之乃武官公堂。此堂正是大理国司马范
烨的司所，司马责属军务，大理四境安宁，为数不多的兵马主要负责边境地区的
治安而已。
LONG);
	set("objects", ([
		__DIR__"npc/fan-ye" : 1,
		]));
	set("exits", ([
		"south" : __DIR__"sangong",
		]));
	set("cost", 1);
	set("wangfu", 1);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	setup();
	replace_program(ROOM);
}
