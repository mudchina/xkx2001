//Cracked by Roath
// Room: /city/majiu.c
// Cleansword 1996/12/01

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", YEL"马厩"NOR);
        set("long", @LONG
这是客栈边上的马厩，常年供应新鲜草料。据说此地民风淳朴，客人只要住
店，马夫们就会把马牵到马厩好生照看，将它们喂饱饮足，再洗刷得干乾净净。
一直伺候到客人离店上路。马厩中堆放著几堆草料，正中有一口泔槽。当你一脚
步入这里，迎面就听见马夫殷勤的笑声。
LONG
        );

        set("objects", ([
		"/clone/obj/car" : 2,
		"/d/shaolin/npc/ma-fu" : 1,
		"/clone/horse/xiaoma" : 2,
		"/clone/horse/huangma" : 1,
		"/clone/horse/qingma" : 1,
		"/d/shaolin/obj/caoliao" : 2,
        ]));

        set("exits", ([
		"south" : __DIR__"kedian",
		"southeast" : __DIR__"beidajie1",
        ]));

        set("outdoors", "city");
        set("resource/water",1);
        set("cost",1);

        setup();
        replace_program(ROOM);
}
