//Cracked by Roath
// Room: /d/heimuya/majiu.c
// fear 1999/12/08

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", YEL"马厩"NOR);
        set("long", @LONG
这是平定客店里的马厩，常年供应新鲜草料。客人
只要住店，马夫们就会把马牵到马厩好生照看，将它们
喂饱饮足，再洗刷得干乾净净。一直伺候到客人离店上
路。马厩中堆放著几堆草料，正中有一口泔槽。
LONG
        );

        set("objects", ([
                "/d/shaolin/npc/ma-fu" : 1,
                "/clone/horse/donkey" : 1,
                "/clone/horse/huangma" : 1,
                "/clone/horse/heima" : 1,
                "/clone/horse/hongma" : 1,
                "/d/shaolin/obj/caoliao" : 2,
        ]));

        set("exits", ([
                "east" : __DIR__"kedian",
                "south" : __DIR__"weststreet2",
        ]));

        set("resource/water",1);
        set("outdoors", "heimuya");
        set("cost",1);

        setup();
        replace_program(ROOM);
}
