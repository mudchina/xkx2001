//Cracked by Roath
inherit ROOM;

void create()
{
	set("short", "灯笼库");
	set("long",  @LONG
这里是紫禁城御林军驻扎休息地方。一排排的通铺靠着墙搭着，
屋内陈设颇为简朴．这里地方虽不大，但竟然住了三百余人。
LONG
	);

	set("exits", ([
		"north" : __DIR__"wuyingmen",
	]));

	setup();
	replace_program(ROOM);
}
