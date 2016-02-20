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
湖。北边可上雷峰，南边是净慈寺。
LONG);

    set("exits", ([ /* sizeof() == 4 */ 
                   "east" : __DIR__"road71", 
                   "west" : __DIR__"road73", 
                   "south" : __DIR__"jingci1", 
                   "northup" : __DIR__"xizhao1", 
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
