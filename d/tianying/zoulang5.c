//Cracked by Roath
// room: zoulang5.c

inherit ROOM;

void create()
{
        set("short", "走廊");
        set("long", @LONG
这是一条非常精美的走廊，柱子和栏杆是用华贵的紫檀木制成，
上面雕饰着美丽的图画，画工精巧，美不胜收。走廊的南边是一座大
殿，北边通往神蛇坛。
LONG );

        set("exits", ([
                "north" : __DIR__"shenshetan",
                "south" : __DIR__"dadian",
        ]));

        set("outdoors", "tianying" );

        setup();
        replace_program(ROOM);
}
