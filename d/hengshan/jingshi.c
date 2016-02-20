//Cracked by Roath
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "静室");
        set("long", 
"这是恒山弟子打坐，练功，修习之所，几个女弟子正坐在蒲
团上闭目修行。\n"
        );
        set("exits", ([
                "east"  : __DIR__"wusean",
                "west"  : __DIR__"sleeproom"
]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

