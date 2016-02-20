//Cracked by Roath
// Room: /d/heimuya/northgate.c
// Date: fear 99/12/08

inherit ROOM;




void create()
{
        set("short", "平定州北门");
        set("long", @LONG
这里是平定州的北门，平时出入的人比较少，四周
静悄悄的。往北去可以看见一片树林。
LONG
        );

        set("exits", ([
                "north" : __DIR__"forest",
                "south" : __DIR__"northstreet1",
        ]));

        set("outdoors", "heimuya");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

