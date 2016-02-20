//Cracked by Roath
// Room: /d/heimuya/weststreet2.c
// Date: fear 1999/12/08

inherit ROOM;




void create()
{
        set("short", "西长街");
        set("long", @LONG
这是平定州的西长街，周围有很多店铺，街上满满
的尽是来往做买卖的人。北面便是平定客店的马厩。
LONG
        );

        set("exits", ([
                "east" : __DIR__"weststreet1",
                "north" : __DIR__"majiu",
        ]));

        set("outdoors", "heimuya");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

