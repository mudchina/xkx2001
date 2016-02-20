// Room: /d/taohuacun/taohua6.c

inherit ROOM;

void create()
{
	set("short", "桃花汀");
	set("long", @LONG
桃花汀在桃花溪边。一桃一柳，夹溪成趣。翠柳长条，依风怜
惜，似有无尽风情。碧水徜佯，落红时节，满目飘零，另有一般情
趣。汀西一望处，有点点精巧漂亮的小别墅，真是住家好去处。
LONG );
	set("outdoors", "city");
	set("no_clean_up", 0);
	set("exits", ([
                "north"     : __DIR__"taohua8",
		"south"     : __DIR__"taohua2",
                "west"      : __DIR__"taohua7",
	]));
	set("objects", ([
		__DIR__"npc/taohuatong" : 1,
	]));
	setup();
	replace_program(ROOM);
}
