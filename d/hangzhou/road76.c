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
湖。大道伸向东北和南两边，往北是另一条大道。
LONG	);

    set("exits", ([ /* sizeof() == 3 */ 
                   "northeast" : __DIR__"road75", 
                   "south" : __DIR__"road77", 
                   "west" : __DIR__"road66", 
                 ])
       );
	set("cost", 1);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}
