//Cracked by Roath
// /d/shenlong/beach.c
// by ALN Sep / 97

#include <ansi.h>

inherit HARBOR;

void create()
{
        set("short", "海岸");
        set("long", @LONG
这是神龙岛的出海口，浪花拍打着礁石，发出阵阵响声，海面上一群群海
鸥『欧欧..』地叫着，不时有鱼儿跃出海面，溅起层层的浪花。边上有艘大船
(chuan)， 船上坐着几个船夫打扮的人，乘船可渡过大海到达海的另一端。东
面是神龙岛的海滩。
LONG
        );

        set("outdoors", "shenlong");

        set("exits", ([
                "east" : __DIR__"haitan",
        ]));

        set("item_desc", ([
                "chuan" : "这是一艘海船，可载人渡海，但是船家在平时也用它来打鱼。\n",
        ]));

        set("objects", ([
    //             "kungfu/class/shenlong/bailong" : 1,
    //             "/d/shenlong/npc/bai" : 1,
        ]));

        set("island", "神龙岛");
        set("shape", "出现一片陆地。");
        set("navigate/locx", 30);
        set("navigate/locy", 20);

        set("cost", 3);

        setup();
}
