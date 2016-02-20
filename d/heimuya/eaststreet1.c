//Cracked by Roath
// Room: /d/heimuya/eaststreet1.c
// Date: fear 99/12/08

inherit ROOM;




void create()
{
        set("short", "东长街");
        set("long", @LONG
这是平定州的东长街，路上行人熙熙攘攘。大街的
北边有间米行，西首便是平定州的中心。
LONG
        );

        set("exits", ([
                "west" : __DIR__"center",
                "east" : __DIR__"eaststreet2",
                "north" : __DIR__"mihang",
        ]));

        set("outdoors", "heimuya");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

