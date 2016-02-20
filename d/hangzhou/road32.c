//Cracked by Roath
// 大道
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{       set("short", "大道");
        set("long", @LONG
大道两边遍植青松，满目苍翠，偃盖如雪。被称为“九里雪松”。
东边是洪春桥，西边便到了灵隐寺，南边一直向前可达浙南和闽北。
LONG);
        set("exits", ([ /* sizeof() == 2 */ 
                  "east" : __DIR__"hongchun",
                  "southup" : __DIR__"road41",
                  "west" : __DIR__"road33", 
                  "northwest" :  "/d/taihu/nanxun",
                ])
        );
	set("cost", 1);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}
