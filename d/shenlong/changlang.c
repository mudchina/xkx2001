//Cracked by Roath
// 长廊 /d/shenlong/changlang.c
// ALN Sep / 97

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "长廊");
        set("long", @LONG
这是一条长廊，西面通向大厅，东面是峰顶，周围挂满了树叶、青藤，边
上有许多小石凳可供人休息。一些凳子上面三三两两地坐了许多神龙教的弟子，
正在七嘴八舌地谈论着什么。
LONG
        );
        set("cost", 1);
        set("outdoors", "shenlong");

        set("exits", ([
                "east": __DIR__"tingkou",
                "west": __DIR__"fengding",
        ]));

        set("objects", ([
                "/kungfu/class/shenlong/fang" : 1,
        ]));

        setup();
}
