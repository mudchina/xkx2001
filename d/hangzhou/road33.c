//Cracked by Roath
// 青石大道
// Dong  11/03/1996.
// modified by aln  2 / 98

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{   
        set("short", "青石大道");
        set("long", @LONG
大道上游人，或步行，或趁轿，或骑马。个个都喜气洋洋。西南
边是灵隐寺和飞来峰。往南是上天竺。
LONG
        );

        set("exits", ([ /* sizeof() == 3 */ 
                 "southup" : __DIR__"tianzhu0",
                 "west" : __DIR__"road34",
                 "east" :  __DIR__"road32",
        ]));

	set("cost", 1);
        set("outdoors", "hangzhou");

        setup();
        replace_program(ROOM);
}
