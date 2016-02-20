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
湖。东北和西边各是一条大道。西南边是上玉皇山的山路。
LONG);

    set("exits", ([ /* sizeof() == 3 */ 
                   "northeast" : __DIR__"road25", 
                   "west" : __DIR__"road72", 
                   "southwest" : __DIR__"yuhuang1", 
                 ])
       );
	set("objects",([
                "/d/taishan/npc/tangzi" : 2,
        ]));
	set("cost", 1);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}
