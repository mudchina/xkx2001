//Cracked by Roath
// Room: /d/heimuya/jiudian.c
// Date: fear 1999/12/08

inherit ROOM;




void create()
{
        set("short", "平定酒店");
        set("long", @LONG
这里是平定州唯一的酒店，柜台边一名店伴伏在桌
上打盹，似乎并酒客不多，只有一旁座上两三名酒客正
在赌骰子。酒店的东边大门口是平定州的北长街。
LONG
        );

        set("exits", ([
                "east" : __DIR__"northstreet1",
        ]));

        set("objects", ([
                __DIR__"npc/dianban" : 1,
                __DIR__"npc/jiuke" : 1,
        ]));

        set("cost", 1);
        setup();
        replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        if( present("xiao er", me) && dir="east" )
                return notify_fail("好端端地你想带店小二到那里去？！\n");

        return ::valid_leave(me, dir);
}

