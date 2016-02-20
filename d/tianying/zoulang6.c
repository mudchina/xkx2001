//Cracked by Roath
// room: zoulang6.c

inherit ROOM;

void create()
{
        set("short", "走廊");
        set("long", @LONG
这是一条非常精美的走廊，柱子和栏杆是用华贵的紫檀木制成，
上面雕饰着美丽的图画，画工精巧，美不胜收。走廊的西边可达紫微
堂，东边是天微堂。
LONG );

        set("exits", ([
                "east" : __DIR__"tianweitang",
                "west" : __DIR__"ziweitang",
		"south" : __DIR__"changlang1",
        ]));

        set("outdoors", "tianying" );

        setup();
        replace_program(ROOM);
}
