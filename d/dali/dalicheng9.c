//Cracked by Roath
// Room: /d/dali/dalicheng9.c

inherit ROOM;

void create()
{
	set("short", "中心广场");
	set("long", @LONG
这里就是阳苜咩城的中心，彩色石块铺成的大道向四方伸延。广场呈菱形，
一圈围的都是小贩，艺人，和看热闹的。熙熙攘攘的人群中也少不了几个跑江湖
之人，一些在中原闻所未闻的事物令一些刚入江湖之人兴奋不已。
LONG);
	set("objects", ([
		__DIR__"npc/yiren" : 1,
		]));
	set("exits", ([
		"south" : __DIR__"dalicheng12",
		"north" : __DIR__"dalicheng2",
		"east" : __DIR__"dalicheng10",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
