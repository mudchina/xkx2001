//Cracked by Roath
// Room: /d/heimuya/hillroad4.c
// Date: fear 1999/12/08

inherit ROOM;




void create()
{
        set("short", "山道");
        set("long", @LONG
这条山道转折弯曲而上，地势极险，道旁便是万丈
深谷。
LONG
        );

        set("exits", ([
                "southdown" : __DIR__"hillroad3",
                "north" : __DIR__"zongtan",
        ]));

        set("outdoors", "heimuya");
        set("cost", 3);
        setup();
        replace_program(ROOM);
}

