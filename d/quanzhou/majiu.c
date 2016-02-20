//Cracked by Roath
// Room: /city/majiu.c
// Cleansword 1996/12/01

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", YEL"马厩"NOR);
        set("long", @LONG
这是客栈边上的马厩，常年供应新鲜草料。据说此地民风淳朴，客人只要
住店，马夫们就会把马牵到马厩好生照看，将它们喂饱饮足，再洗刷得干乾净
净。一直伺候到客人离店上路。马厩中堆放著几堆草料，正中有一口泔槽。
LONG
        );

        set("objects", ([
		"/d/shaolin/npc/ma-fu" : 1,
//		"/clone/horse/gaoma" : 2,
		"/clone/obj/car" : 1,
		"/clone/horse/hongma" : 1,
		"/d/shaolin/obj/caoliao" : 2,
        ]));

        set("exits", ([
		"west" : __DIR__"qzkedian",
        ]));

        set("resource/water",1);
	set("outdoors", "quanzhou");
        set("cost",1);

        setup();
//	replace_program(ROOM);
}
