//Cracked by Roath
// Room: /d/heimuya/smallhill1.c
// Date: fear 99/12/08

inherit ROOM;




void create()
{
        set("short", "小山坡");
        set("long", @LONG
这是平定州外的小山坡，到处是尽是荒山野岭。在
山坡上遥望北方，似乎可以看见远处平定州稀稀落落的
店铺和房舍。
LONG
        );

        set("exits", ([
                "southeast" : __DIR__"road2",
                "northup" : __DIR__"smallhill2",
        ]));

        set("outdoors", "heimuya");
        set("cost", 2);
        setup();
        replace_program(ROOM);
}

