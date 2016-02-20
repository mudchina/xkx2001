//Cracked by Roath
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "飞桥");
        set("long", 
"飞桥阔仅数尺，连接灵龟神蛇两阁，若是常人登临，放眼四周
皆空，云生足底，有如身处天上，自不免心目俱摇，手足如废，但
如果武林高手临此胜境，则胸襟大畅。\n");
        
set("exits", ([
                "west"  : __DIR__"shenshege",
                "east"   : __DIR__"lingguige",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "hengshan");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

