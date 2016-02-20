//Cracked by Roath
// Room: /d/heimuya/road1.c
// Date: fear 99/12/08

inherit ROOM;




void create()
{
        set("short", "青石大道");
        set("long", @LONG
这是一条平直的大道，地面由青石板铺成，两旁都
是浓密的树林。道上不时有人来车往，看来甚是繁忙。
LONG
        );

        set("exits", ([
                "southeast" : "/d/beijing/yidao3",
                "northwest" : __DIR__"road2",
        ]));

        set("outdoors", "heimuya");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

