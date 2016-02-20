//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov44.c

inherit ROOM;

void create()
{
	set("short", "东泸水河谷");
	set("long", @LONG
西面这一大片河谷处在碧罗雪山和高黎山之间，由东泸水冲刷而成，地势低
洼，因而气候较温暖，聚居了大量乌夷族人。乌夷先民沿河谷开发了一些梯田。
四周山高林密，男子多从事狩猎。沿着脚下的向西直抵一个大镇子。
LONG);
	set("exits", ([
		"northdown" : __DIR__"minov57",
		"westdown" : __DIR__"minov53",
		"eastup" : __DIR__"minov42",
		"south" : __DIR__"minov45",
		]));
	set("area", "碧罗雪山");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
