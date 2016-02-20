//Cracked by Roath
// Room: /d/heimuya/heimulin1.c
// Date: fear 99/12/08

inherit ROOM;




void create()
{
        set("short", "黑木林边");
        set("long", @LONG
这里是树林的边缘，树林边可以望见里面浓密高大
的树木。传说树林深处有个令人闻之丧胆的妖兽，有很
多来这里伐木的樵夫都迷失在这里，再也没有回去了。
LONG
        );

        set("exits", ([
                "west" : __DIR__"forest",
                "northeast" : __DIR__"heimulin2",
        ]));

        set("objects", ([
                "/clone/beast/deer" : 1,
        ]));

        set("outdoors", "heimuya");
        set("cost", 2);
        setup();
        replace_program(ROOM);
}

