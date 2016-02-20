//Cracked by Roath
// room: zoulang4.c

inherit ROOM;

void create()
{
        set("short", "走廊");
        set("long", @LONG
这是一条非常精美的走廊，柱子和栏杆是用华贵的紫檀木制成，
上面雕饰着美丽的图画，画工精巧，美不胜收。走廊的北边是白虎坛
，南边是朱雀坛。
LONG );

        set("exits", ([
                "north" : __DIR__"baihutan",
                "south" : __DIR__"zhuquetan",
		"west" : __DIR__"zoulang3",
        ]));

        set("outdoors", "tianying" );

        setup();
        replace_program(ROOM);
}
