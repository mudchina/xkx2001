//Cracked by Roath
// Room: /d/heimuya/hillroad1.c
// Date: fear 1999/12/08

inherit ROOM;




void create()
{
        set("short", "山道");
        set("long", @LONG
这是条阴暗的山道，旁边树木高大，道路极是陡峭。
LONG
        );

        set("exits", ([
                "westdown" : __DIR__"shuitan2",
                "northup" : __DIR__"hillroad2",
        ]));

        set("outdoors", "heimuya");
        set("cost", 3);
        setup();
        replace_program(ROOM);
}

