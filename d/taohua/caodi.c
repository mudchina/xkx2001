//Cracked by Roath
//Chaos, Ryu, 3/10/97

inherit ROOM;

void create()
{
	set("short", "草地");
	set("long", @LONG
这是一块极普通的草地，地上只有一些寻常随处可见的小石子和小树枝。东面有
一条小径，西面是茂密的树林，北面则是一座松柏林，松柏林中一条小路蜿蜒向北，
不知所终。
LONG
	);
	 set("exits", ([
                "west" : __DIR__"shucong",
                "east" : __DIR__"xiaojing",
                "north" : __DIR__"songlin",
        ]));
	set("cost", 2);
	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}
