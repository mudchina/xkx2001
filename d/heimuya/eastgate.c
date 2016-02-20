//Cracked by Roath
// Room: /d/heimuya/eastgate.c
// Date: fear 99/12/08

inherit ROOM;




void create()
{
        set("short", "平定州东门");
        set("long", @LONG
这里是平定州的东门，平时行人络绎不绝的来来往
往。东南方是一片山坡，有一条黄土小径在山坡蜿蜒而
上。
LONG
        );

        set("exits", ([
                "west" : __DIR__"eaststreet2",
                "southup" : __DIR__"smallhill2",
        ]));

        set("outdoors", "heimuya");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

