//Cracked by Roath
// Ryu, 5/10/97

inherit ROOM;

void create()
{
	set("short", "阿拉沟");
	set("long", @LONG
山沟渐窄，飞流奔泻，水声不绝，夹岸柳榆丛生，间或还有小块
农田菜畦，郁郁青青，绵延一百多里。阿拉沟水虽然已成了涓涓小溪，
但却更加清澈干冽。一个个穿着彩色绸裙、手提葫芦、陶罐的锡伯少
女，在清清的涝坝边汲水，水中倒映着她们婀娜的身影。
LONG
	);
	set("exits", ([
		"northup" : __DIR__"lake",
		"south" : __DIR__"alagou1",
	]));
	set("objects", ([
		__DIR__"npc/xbgirl": 2,
	]));
	set("cost", 2);
	set("resource/water",1);
	set("outdoors", "tianshan");

	setup();
	replace_program(ROOM);
}
