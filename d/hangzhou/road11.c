//Cracked by Roath
// 青石大道
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{       set("short", "青石大道");
        set("long", @LONG
大道上游人，或步行，或趁轿，或骑马。个个喜气洋洋的来游西
湖。大道延伸向西边。断桥在大道的西南边。南边则是另一条大道。
LONG);

        set("exits", ([ /* sizeof() == 3 */ 
                "south" : __DIR__"road20",
                "southwest" : __DIR__"duanqiao",
                "west" : __DIR__"road12",
        ]));

	set("cost", 1);
        set("outdoors", "hangzhou");

        setup();
        replace_program(ROOM);
}
