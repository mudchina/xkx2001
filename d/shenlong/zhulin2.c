//Cracked by Roath
//竹林1 /d/shenlong/zhulin1
// ALN Sep / 97

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "竹林");
        set("long", @LONG
这儿是一片密实的竹林，光线暗淡，你一不小心就会被脚下的枝条绊个跟头。
附近似乎有轻微的沙沙声，好象是海风吹过又好象是虫子爬过，你觉得有点不对
劲，但又说不出是什么。
LONG
        );

        set("outdoors", "shenlong");
        set("exits", ([
                "south" : __DIR__"zhulin1",
                "north" : __DIR__"liangongfang",
        ]));

        set("cost", 1);
        set("snaketype", ({"zsnake"}));

        setup();
}

#include "/d/shenlong/snakeroom.h";
