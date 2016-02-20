//Cracked by Roath
// Room: /d/heimuya/eaststreet2.c
// Date: fear 99/12/08

inherit ROOM;




void create()
{
        set("short", "东长街");
        set("long", @LONG
这是平定州的东长街，街上有很多人潮。往北不远
处有座破祠堂，往东的青石板路笔直的伸展出去直通东
门。
LONG
        );

        set("exits", ([
                "west" : __DIR__"eaststreet1",
                "east" : __DIR__"eastgate",
                "north" : __DIR__"pocitang",
        ]));

        set("outdoors", "heimuya");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

