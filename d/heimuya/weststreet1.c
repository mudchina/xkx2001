//Cracked by Roath
// Room: /d/heimuya/weststreet1.c
// Date: fear 99/12/08

inherit ROOM;




void create()
{
        set("short", "西长街");
        set("long", @LONG
这是平定州的西长街，走到街上可以听见小贩叫卖
的声音。走过北面，有家客店，南面有家杂货铺。长街
道上走过很多人，甚是热闹。
LONG
        );

        set("exits", ([
                "east" : __DIR__"center",
                "west" : __DIR__"weststreet2",
                "north" : __DIR__"kedian",
                "south" : __DIR__"zahuopu",
        ]));

        set("outdoors", "heimuya");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

