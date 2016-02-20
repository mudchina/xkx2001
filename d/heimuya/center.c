//Cracked by Roath
// Room: /d/heimuya/center.c
// Date: fear 99/12/08

inherit ROOM;




void create()
{
        set("short", "平定州中心");
        set("long", @LONG
这里是平定州的中心，属于平定州的交通要冲。四
处人来人往，甚是热闹。东西两面伸延着青石板铺成的
长街道路。
LONG
        );

        set("exits", ([
                "west" : __DIR__"weststreet1",
                "east" : __DIR__"eaststreet1",
                "north" : __DIR__"northstreet1",
        ]));

        set("outdoors", "heimuya");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

