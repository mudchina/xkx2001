//Cracked by Roath
// room: yuanzi.c

inherit ROOM;

void create()
{
        set("short", "院子");
        set("long", @LONG
这是一个静悄悄的院子。院子里种着几棵大槐树，把热辣辣的阳
光遮住。树上不时的传来几声鸟叫，令人甚感舒适。院子的东面和南
面有几间大的睡房。
LONG );

        set("exits", ([
                "east" : __DIR__"xiangfang1",
                "south" : __DIR__"xiangfang2",
		"west" : __DIR__"guangchang",
        ]));

        set("outdoors", "tianying" );

        setup();
        replace_program(ROOM);
}
