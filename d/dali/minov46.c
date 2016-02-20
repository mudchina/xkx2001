//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov46.c

inherit ROOM;

void create()
{
	set("short", "碧罗山下");
	set("long", @LONG
此间正处碧罗山脚下，几层梯田沿山坡而上，土地看来一点也不肥沃，作物
较稀疏。乌夷地区农业颇落后，行换季轮耕，村民在不同的季节耕作不同的田地
，许多附近的梯田正荒芜着无人耕作。
LONG);
	set("objects", ([
		__DIR__"npc/wynong" : 1,
		]));
	set("exits", ([
		"southwest" : __DIR__"minov47",
		"southeast" : __DIR__"shanlu1",
		"westup" : __DIR__"minov45",
		]));
	set("area", "碧罗雪山");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
