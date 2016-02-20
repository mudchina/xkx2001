//Cracked by Roath
// Room: /d/heimuya/hillroad3.c
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
                "westdown" : __DIR__"hillroad2",
                "northup" : __DIR__"hillroad4",
        ]));

        set("outdoors", "heimuya");
        set("cost", 3);
        setup();
        replace_program(ROOM);
}

