//Cracked by Roath
// Room: /city/beimen.c
// YZC 1995/12/04 

#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
        set("short", "北门");
        set("long", 
"这里便是远近闻名的扬州城了。许多南来北往的人从这里进进出出。守门的
官兵正上下盯着你。你往城里望去，一片繁华的景象。北边是一条青石大道，人
来人往。城墙上挂了一个告示(gaoshi)。\n"
        );

        set("item_desc", ([
                "gaoshi" : (:look_gaoshi:),
        ]));

        set("exits", ([
                "south" : __DIR__"beidajie2",
                "north" : "/d/village/hsroad1",
                "east" : __DIR__"beijiao1",
                "west" : __DIR__"beijiao3",
        ]));
        set("objects", ([
                __DIR__"npc/wujiang" : 1,
                __DIR__"npc/bing" : 2,
        ]));
        set("outdoors", "city");
        set("cost", 1);
        setup();
}

string look_gaoshi()
{
        return FINGER_D->get_killer() + "\n浙江提督\n李克秀\n";
}
int valid_leave(object me, string dir)
{
        if (dir =="south" )
        if(present("guan bing", (environment(me)))
        && me->query_condition("killer") > 0)
                return notify_fail("官兵手中的刀挡住了你的去路。\n");
        return ::valid_leave(me, dir);
}