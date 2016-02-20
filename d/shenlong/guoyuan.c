//Cracked by Roath
// /d/shenlong/guoyuan.c
// ALN Sep / 97

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "果园");
        set("long", @LONG
这是一片果园，种的是一些水果，有苹果、梨头、山揸、桃子、杏子、梅
子等，有的已到的收获时节，枝头已被果实压弯了腰，沉甸甸的，风一吹枝头
一颤一颤的，叫人看了直流口水。西面、北面似乎仍是农田，南面是山丘，东
面是一道山岗。
LONG
        );
        set("outdoors", "shenlong");
        set("exits", ([
                "south" : __DIR__"shanqiu",
        ]));
        set("objects", ([
            "/d/shenlong/obj/apple" : 2 + random(8),
        ]));
        set("cost", 3);
        set("snaketype", ({"jinhuan"}));
        setup();
}

#include "/d/shenlong/snakeroom.h";
