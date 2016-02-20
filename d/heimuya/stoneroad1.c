//Cracked by Roath
// Room: /d/heimuya/stoneroad1.c
// Date: fear 99/12/08

inherit ROOM;




void create()
{
        set("short", "石路");
        set("long", @LONG
这是条石路，路边左首的山石殷红如血，右边是一
片长滩，水流湍急，那便是有名的猩猩滩。往南边去是
一片黑压压的树林。
LONG
        );

        set("exits", ([
                "northwest" : __DIR__"stoneroad2",
                "south" : __DIR__"heimulin5",
        ]));

        set("outdoors", "heimuya");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

