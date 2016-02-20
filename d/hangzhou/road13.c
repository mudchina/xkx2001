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
湖。大道延伸向西边和东北边。朝北走便是上北山。南边则通往西冷
桥。
LONG);

    set("exits", ([ /* sizeof() == 4 */ 
                  "east" : __DIR__"road12", 
                  "west" : __DIR__"road14", 
                  "north" : __DIR__"beishan1", 
                  "south" : __DIR__"xileng", 
                 ])
       );
	set("objects", ([
                "/d/taishan/npc/tangzi" : 2,
        ]));
	set("cost", 1);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}
