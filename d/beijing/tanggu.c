//Cracked by Roath
// /d/shenlong/tanggu.c
// ALN Sep / 97

#include <ansi.h>

inherit HARBOR;

void create()
{
        set("short", "塘沽口");
        set("long", @LONG
这里就是大海之滨，浪花拍打着礁石，发出阵阵响声，海面上一群群海
鸥『欧欧..』地叫着，不时有鱼儿跃出海面，溅起层层的浪花。边上有艘大
船(chuan)，船上坐着几个渔夫打扮的人，乘船可渡过大海到达海的另一端。
西面是天津城，东面是一望无际的大海。
LONG
        );

        set("outdoors", "shenlong");
        set("exits", ([
                "west" : __DIR__"yidao3",
        ]));

        set("item_desc", ([
                "chuan" : "这是一艘海船，可载人渡海，但是船家在平时也用它来打鱼。\n",
        ]));

        set("objects", ([
      //    "/d/shenlong/npc/yufu1" : 1,
            "/clone/obj/car" : 1,
        ]));

        set("navigate/locx", 0);
        set("navigate/locy", 0);

        set("cost", 2);

        setup();
}
