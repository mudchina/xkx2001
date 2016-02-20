//Cracked by Roath
// 青石大道
// Dong  11/03/1996.
// modified by aln 2 / 98

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{   set("short", "青石大道");
    set("long", @LONG
大道上游人，或步行，或趁轿，或骑马。个个喜气洋洋的来游西
湖。往西是洪春桥。大道则延伸向东北边。
LONG      );

         set("exits", ([ /* sizeof() == 2 */ 
                  "west" : __DIR__"hongchun", 
                  "northeast" : __DIR__"road15", 
                ])
        );
	set("cost", 1);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}
