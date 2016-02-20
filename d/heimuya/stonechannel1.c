//Cracked by Roath
// Room: /d/heimuya/stonechannel.c
// Date: fear 99/12/08

inherit ROOM;




void create()
{
        set("short", "石道");
        set("long", @LONG
这是条狭窄弯曲的石道，道路两边石壁如墙，中间
仅有一道宽约五尺的石道。
LONG
        );

        set("exits", ([
                "southeast" : __DIR__"stoneroad2",
                "north" : __DIR__"stonechannel2",
        ]));

        set("outdoors", "heimuya");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

