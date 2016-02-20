//Cracked by Roath
// Room: /city/dongdajie1.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "东大街");
	set("long", @LONG
这是一条宽阔的青石板街道，向东西两头延伸。东边不时地传来金属撞击声，
西边人声嘈杂。北边是一座简朴的院子，半月形的大门上方写着“白鹿书院”四
个烫金大字，苍劲有力。里面不时地传来学生们抑扬顿挫的读书声。南边是一家
杂货铺。
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"east" : __DIR__"dongdajie2",
		"south" : __DIR__"zahuopu",
		"west" : __DIR__"guangchang",
		"north" : __DIR__"shuyuan",
	]));
        set("objects", ([
                __DIR__"npc/xunbu" : 1,
        ]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

