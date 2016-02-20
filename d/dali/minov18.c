//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov18.c

inherit ROOM;

void create()
{
	set("short", "滇池南岸");
	set("long", @LONG
滇池名曰池，实际上是个很大的湖，四面山上水源众多，也浇灌了大片的农
田。池水清澈凉爽，许多罗伽部的妇女在此洗衣挑水。摆夷并不以渔业为主，不
过岸边仍然建有小码头，时常有游船停靠，也有少量竹舟下水打鱼。西边有条弯
弯曲曲的小路沿着滇池南岸而去。
LONG);
	set("objects", ([
		__DIR__"npc/bywoman.c" : 2,
		]));
	set("exits", ([
		"northeast" : __DIR__"minov17",
		"west" : __DIR__"minov19",
		]));
	set("area", "罗伽甸");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
