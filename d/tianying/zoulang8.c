//Cracked by Roath
// room: zoulang8.c

inherit ROOM;

void create()
{
        set("short", "走廊");
        set("long", @LONG
这是一条非常精美的走廊，柱子和栏杆是用华贵的紫檀木制成，
上面雕饰着美丽的图画，画工精巧，美不胜收。走廊的南边可达天微
堂，北边是教主大厅。
LONG );

        set("exits", ([
                "north" : __DIR__"dating",
                "south" : __DIR__"tianweitang",
        ]));

        set("outdoors", "tianying" );

        setup();
        replace_program(ROOM);
}
