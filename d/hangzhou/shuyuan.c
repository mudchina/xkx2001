//Cracked by Roath
// 凤池书院
// modified by aln  2 / 98

// NTD:  NPC and object. 

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{       set("short", "玉泉书院");
        set("long", @LONG
书院正中有一匾“玉泉书院”。书院里坐着两位老者，他们正在
吟诗作对。他们身旁的桌上铺着宣纸和笔墨。
LONG);

        set("objects", ([
                __DIR__"npc/gu" : 1,
                
        ]));

        set("exits", ([ /* sizeof() == 1 */ 
                   "east" : __DIR__"yuquan", 
        ]));

	set("cost", 1);

        setup();
        replace_program(ROOM);
}
