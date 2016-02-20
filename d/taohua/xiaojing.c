//Cracked by Roath
//Chaos, Ryu, 3/10/97

inherit ROOM;

void create()
{
	set("short", "小径");
	set("long", @LONG
这是一条由大青条石铺成的小路，虽不能说是一尘不染，但也整整洁洁，
看来经常有人打扫。东北面有一个小土丘，西面是一块草地，东面有一座树林。
LONG
	);
	 set("exits", ([
                "west" : __DIR__"caodi",
                "east" : __DIR__"shulin",
                "north" : __DIR__"tuqiu",
		"south" : __DIR__"haitan",
        ]));
	set("cost", 2);
	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}
