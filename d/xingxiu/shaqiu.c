//Cracked by Roath
// shaqiu.c
// maco

inherit ROOM;

void create()
{
    int i;
	set("short", "沙丘");
	set("long", @LONG
这里是一望无际的沙漠，四顾茫茫，尽是沙丘，南边的沙丘间
现出稀稀落落的铁草。
LONG
	);

	set("exits", ([
		"east" : __DIR__"shamo1",
		"west" : __DIR__"shamo2",
		"south" : __DIR__"luzhou2",
		"north" : __DIR__"shamo4",
	]));
	set("outdoors","xingxiu");
	set("cost", 2);
	setup();
	replace_program(ROOM);
}

