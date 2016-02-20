//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov42.c

inherit ROOM;

void create()
{
	set("short", "碧罗雪山");
	set("long", @LONG
你身处一片大雪山之中，此地只是半山腰，却已经积雪皑皑，寒风刺骨了。
仰头望去，银白的峰尖似在云中，天空也蓝得特别深邃。由此向上的山颠杳无生
命的踪迹，只向下百丈的山腰便是树木苍郁、飞禽走兽横行的世界了。向东不远
有一条大河流过，在崇山峻岭之间冲击出一片谷地。
LONG);
	set("exits", ([
		"southdown" : __DIR__"minov43",
		"westdown" : __DIR__"minov44",
		"eastdown" : __DIR__"minov41",
		]));
	set("area", "碧罗雪山");
	set("cost", 5);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
