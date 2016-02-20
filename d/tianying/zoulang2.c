//Cracked by Roath
// room: zoulang2.c

inherit ROOM;

void create()
{
        set("short", "走廊");
        set("long", @LONG
这是一条非常精美的走廊，柱子和栏杆是用华贵的紫檀木制成，
上面雕饰着美丽的图画，画工精巧，美不胜收。走廊的北边通往青龙
坛，南边是玄武坛。
LONG );

        set("exits", ([
                "north" : __DIR__"qinglongtan",
                "south" : __DIR__"xuanwutan",
		"east" : __DIR__"zoulang1",
        ]));

        set("outdoors", "tianying" );

        setup();
        replace_program(ROOM);
}
