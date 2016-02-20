//Cracked by Roath
// Room: /city/majiu.c
// Cleansword 1996/12/01

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", YEL"马厩"NOR);
        set("long", @LONG
这是一间马厩，常年供应新鲜草料。此地民风淳朴，马夫们把马牵到马厩
好生照看，将它们喂饱饮足，再洗刷得干乾净净，一直伺候到客人离店上路。
马厩中堆放著几堆草料，正中有一口泔槽。
LONG
        );

        set("objects", ([
		"/d/shaolin/npc/ma-fu" : 1,
		"/clone/horse/baima" : 2,
		"/clone/horse/heima" : 1,
		"/d/shaolin/obj/caoliao" : 2,
        ]));

        set("exits", ([
		"south" : __DIR__"huayanding",
        ]));

        set("resource/water",1);
        set("cost",1);
	set("outdoors", "emei");

        setup();
        replace_program(ROOM);
}
