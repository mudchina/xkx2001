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
湖。往西是去玉泉寺的路。大道则延伸向东边和西南边。
LONG);

    set("exits", ([ /* sizeof() == 4 */ 
                   "east" : __DIR__"road14", 
                   "westup" : __DIR__"yuquan", 
                   "southwest" : __DIR__"road31", 
                   "south" : __DIR__"road51", 
                 ])
        );
	set("objects", ([
                "/d/taishan/npc/tiao-fu" : 1,
		"/d/taishan/npc/dao-ke" : 1,
        ]));
	set("cost", 1);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}
