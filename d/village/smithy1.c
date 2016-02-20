//Cracked by Roath
// Room: /d/village/smithy1.c

inherit ROOM;

void create()
{
        set("short", "铁匠铺");
        set("long", @LONG
这是一间甚是简陋的铁匠铺，门口挂着一块大牌子(paizi)，入门正中是个大铁
砧，满地煤渣碎铁，墙上挂着几张犁头，屋子的角落里堆着几把破锄头、镰刀，靠
墙放着几把新出炉的铁锤。东面有一个小门，门上挂著个破布帘。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"smithy2",
  "north" : __DIR__"eroad3",
]));
         set("item_desc", ([
                "paizi" : "本铺收购废铁\n",
        ]));
        set("no_clean_up", 0);
        set("objects", ([
                __DIR__"npc/smith": 1 ]) );

        set("cost", 0);
        setup();
        replace_program(ROOM);
}
