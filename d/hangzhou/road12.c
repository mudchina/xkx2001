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
湖。大道延伸向东边和西南边。朝北走便是上宝石山。
LONG);

    set("exits", ([ /* sizeof() == 4 */ 
                   "east" : __DIR__"road11", 
                   "west" : __DIR__"road13", 
                   "northup" : __DIR__"baoshi1", 
                 ])
       );
	set("cost", 1);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}
