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
湖。大道伸向南北两边，往西是虎跑泉，往东是一条山路。
LONG	);

    set("exits", ([ /* sizeof() == 4 */ 
                   "north" : __DIR__"road76", 
                   "south" : __DIR__"road78", 
                   "west" : __DIR__"hupao1", 
                   "east" : __DIR__"yuhuang5", 
                 ])
       );
	set("objects",([
                "/d/taishan/npc/tiao-fu" : 1,
        ]));
	set("cost", 1);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}
