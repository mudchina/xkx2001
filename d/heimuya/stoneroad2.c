//Cracked by Roath
// Room: /d/heimuya/stoneroad2.c
// Date: fear 99/12/08

inherit ROOM;




void create()
{
        set("short", "石路");
        set("long", @LONG
这是条石路，路边左首的山石殷红如血，右边是一
片长滩，水流湍急，那便是有名的猩猩滩。前面远处似
乎有一条狭小的石道。
LONG
        );

        set("exits", ([
                "southeast" : __DIR__"stoneroad1",
                "northwest" : __DIR__"stonechannel1",
        ]));

        set("outdoors", "heimuya");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

