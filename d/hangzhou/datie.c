//Cracked by Roath
// 张小泉打铁铺
// Dong  11/03/1996.
// Buying food code needed here. !!!

// NTD:  NPC and object. 打铁匠，张小泉，翦刀。

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{   set("short", "铁匠铺");
    set("long", @LONG
这是一家不小的打铁铺，店里摆了几座火炉，一位铁匠正在火炉
旁满头大汗地打造东西。一位老者坐在边上。火炉边放着不少打好了
的铁器。
LONG);

    set("exits", ([ /* sizeof() == 1 */ 
                   "west" : __DIR__"road22", 
                 ])
       );
	set("objects", ([
                "/d/quanzhou/npc/tiejiang" : 1,
		"/d/hangzhou/npc/ouzhizi" : 1,
        ]));
	set("cost", 0);
    setup();
    replace_program(ROOM);
}
