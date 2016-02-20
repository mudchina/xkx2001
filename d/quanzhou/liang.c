//Cracked by Roath
// room: liang.c
//Jay 4/7/96

#include <room.h>

inherit ROOM;

void create()
{ 
       set("short","向阳老宅房梁");
       set("long", @LONG
你现在在密室的房梁上四下观瞧，周围都是些烂木头破砖瓦。突然你瞟见
犄角旮旯处有一件袈裟。
LONG
     );
        set("exits", ([
                "down" : __DIR__"mishi",
        ]));       
        set("objects", ([
                __DIR__"obj/jiasha" : 1,
                "/d/xingxiu/npc/snake" :1,
        ]));       

	set("cost", 2);
        setup();
}

