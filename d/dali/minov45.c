//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov45.c

inherit ROOM;

void create()
{
	set("short", "梯田");
	set("long", @LONG
东泸水河谷气候较温暖，乌夷先民沿山坡开垦了不少梯田。此间乃是低坡，
层层梯田沿坡而上，土地看来并不肥沃，作物较稀疏，乌夷地区农业颇为落后，
多行换季轮耕，附近山上的一些梯田在这个季节正荒芜着。
LONG);
	set("objects", ([
		__DIR__"npc/wynong" : 1,
		]));
	set("exits", ([
		"eastdown" : __DIR__"minov46",
		"north" : __DIR__"minov44",	
		]));
	set("area", "碧罗雪山");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
