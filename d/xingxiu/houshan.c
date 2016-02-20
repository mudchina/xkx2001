//Cracked by Roath
// houshan.c 白玉峰後山
// maco

inherit ROOM;

void create()
{
    int i;
	set("short", "後山小路");
	set("long", @LONG
这是白玉峰下的小路，可以由此从翡翠池绕入城中。
LONG
	);

	set("exits", ([
		"east" : __DIR__"gucheng5",
		"west" : __DIR__"caoyuan1",
	]));
	set("outdoors","xingxiu");
	set("cost", 1);
	setup();
	replace_program(ROOM);
}

