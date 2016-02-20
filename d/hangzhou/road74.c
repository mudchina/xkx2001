//Cracked by Roath
// 青石大道
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{   set("short", "青石大道");
    set("long", @LONG
大道上游人，或步行，或趁轿，或骑马。个个喜气洋洋的来游西
湖。大道伸向东和西南两边，往北是另一条大道。
LONG	);

    set("exits", ([ /* sizeof() == 3 */ 
                   "north" : __DIR__"road54", 
                   "southwest" : __DIR__"road75", 
                   "east" : __DIR__"road73", 
                 ])
       );
	set("objects",([
                "/d/taishan/npc/dao-ke" : 1,
        ]));
	set("cost", 1);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}
