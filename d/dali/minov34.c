//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov34.c

inherit ROOM;

void create()
{
	set("short", "步雄部");
	set("long", @LONG
这里属江川路，是摆夷的一支--些么徒蛮聚居的地方。此地较偏远，镇子也
不大，南面一片汪洋叫做星云湖，四面山清水秀，桑林密布。镇北是一片小平原，
有些农田。此间桑树多，产丝，乡间民妇多擅纺丝织麻。
LONG);
	set("objects", ([
		__DIR__"npc/byshang" : 1,
		]));
	set("exits", ([
		"westup" : __DIR__"minov33",
		"north" : __DIR__"minov38",
		"south" : __DIR__"minov35",
		"east" : __DIR__"minov37",
		]));
	set("area", "步雄部");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
