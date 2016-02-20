//Cracked by Roath
//Chaos, Ryu, 3/10/97

inherit ROOM;

void create()
{
	set("short", "小土丘");
	set("long", @LONG
走到这里，地势才略见起伏。土丘之上虽然没有什么高大树木，但碧草茵茵，
间杂着一些奇花异草，散发出阵阵沁人心肺的异香，令人精神为之一振。居高临
下朝北边望去似乎有一片小小竹林 。
LONG
	);
	 set("exits", ([
                "south" : __DIR__"xiaojing",
                "north" : __DIR__"zhulin",
        ]));
	set("cost", 2);
	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}
