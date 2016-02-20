//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov52.c

inherit ROOM;

void create()
{
	set("short", "泸水沿岸");
	set("long", @LONG
一条土路沿着泸水纵贯谷地南北，脚下泸水滔滔流去，长年累月冲刷着谷中
大地，东面碧罗雪山、西面的高黎山皆高耸蔽日。土路北通此谷中心大镇巴的甸，
南连数个乌夷小部落。
LONG);
	set("exits", ([
		"north" : __DIR__"minov53",
		"south" : __DIR__"minov49",
		]));
	set("area", "泸水沿岸");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
