//Cracked by Roath
// Ryu, 5/10/97

inherit ROOM;

void create()
{
	set("short", "冰川古道");
	set("long", @LONG
这里是天山最高峰——托木尔峰东侧。这条冰川古道，南起阿克
苏克兹布拉克山口，北抵伊犁哈萨，曾是汉通乌孙、大宛的主要商路，
也是联结南、北疆的一条捷径。
LONG
	);
	set("exits", ([
		"northup" : __DIR__"gudao2",
		"westdown" : __DIR__"lake",
	]));
	set("cost", 4);
	set("outdoors", "tianshan");

	setup();
	replace_program(ROOM);
}
