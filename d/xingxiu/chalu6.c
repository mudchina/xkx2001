//Cracked by Roath
// 岔路
// maco

inherit ROOM;

void create()
{
    int i;
	set("short", "乱石岔路");
	set("long", @LONG
此处地势与大漠的其余地方截然不同，遍地黄沙中混着粗大
石砾，丘壑处处，乱岩嶙嶙，十分的崎岖难行。一眼望去，山道
竟有十数条之多，不知哪一条才是正路。
LONG
	);

	set("exits", ([
		"east" : __DIR__"chalu7",
		"northeast" : __DIR__"chalu5",
		"southeast" : __DIR__"chalu4",
		"west" : __DIR__"chalu3",
		"northwest" : __DIR__"chalu"+(6+random(4)),
		"southwest" : __DIR__"chalu2",
	]));
	set("outdoors","xingxiu");
	set("cost", 10);
	setup();
	replace_program(ROOM);
}

