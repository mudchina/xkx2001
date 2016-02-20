//Cracked by Roath
// room: zoulang1.c

inherit ROOM;

void create()
{
        set("short", "走廊");
        set("long", @LONG
这是一条非常精美的走廊，柱子和栏杆是用华贵的紫檀木制成，
上面雕饰着美丽的图画，画工精巧，美不胜收。走廊的东边是一座大
殿。
LONG );

        set("exits", ([
                "east" : __DIR__"dadian",
                "west" : __DIR__"zoulang2",
		"north" : __DIR__"changlang1",
        ]));

        set("outdoors", "tianying" );

        setup();
        replace_program(ROOM);
}
