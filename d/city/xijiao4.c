//Cracked by Roath
// room: /d/city/xijiao4.c
// Jay 7/4/96

#include <ansi.h>;
inherit ROOM;

void create()
{

        set("short", "草地");
        set("long", 
"这里是一遍绿茵茵的草地，像是一方绿色的毯子铺在地上。草丛中开着一些
不知名的小花，有"+HIR"红"NOR+"的、"+HIY"黄"NOR+"的，还有"+MAG"紫"NOR+"的。花瓣上、草叶上的露珠闪着晶莹的光。\n"
        );

        set("objects", ([
            "/d/city/obj/stone" : 2,
        ]));


        set("exits", ([
                "north" : __DIR__"xijiao3",
                "south" : __DIR__"swforest",
                "southeast" : __DIR__"nanjiao4",
        ]));
        set("outdoors","city");
        set("resource/grass", 1);
        set("cost", 2);
        setup();
        replace_program(ROOM);
}
