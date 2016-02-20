//Cracked by Roath
// Room: /city/caizhu.c
// YZC 1995/12/04 
// Jay 2/3/97 redesign

inherit ROOM;

void create()
{
	set("short", "翰林府门");
	set("long", @LONG
一座富丽堂皇的大宅院出现在你眼前，两头高大的石狮子镇守在大门两侧，
大门上的朱漆足足有三寸厚。门上一张匾，上书“翰林府”三个大字。寻常江湖
人士不敢随便进去。在你偷偷抬眼向里面张望的时候，两条凶猛的大狼狗嚎叫着
向你冲了过来。
LONG
	);

	set("exits", ([
		"south" : __DIR__"xidajie3",
		"north" : __DIR__"dayuan1",
	]));

	set("objects", ([
		__DIR__"npc/wolfdog" : 2,
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

