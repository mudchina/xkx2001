//Cracked by Roath
// room: guangchang.c

inherit ROOM;

void create()
{
        set("short", "广场");
        set("long", @LONG
这里是一个由一块块石板铺成的广场，广场上立着几根旗杆，一
面面天鹰旗随风飘扬。四周是石头砌成的栏杆。广场上人来人往，天
鹰教大的聚会都在这里举行。
LONG );

        set("exits", ([
                "west" : __DIR__"lianwuchang",
                "north" : __DIR__"dadian",
		"east" : __DIR__"yuanzi",
		"south" : __DIR__"road1",
        ]));

        set("outdoors", "tianying" );

        setup();
        replace_program(ROOM);
}
