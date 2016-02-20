//Cracked by Roath
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "通元谷");
        set("long", 
"通元谷位于见性峰下，相传唐时仙人张果老曾在此炼丹。谷中大石
上有蹄印数处，历代相传为张果老所骑驴子踏出。唐玄宗封张果老为“
通元先生”，通元谷之名，便由此而来。由谷中仰望见性峰，无色庵遥
遥可见。
\n"
        );
        set("exits", ([
                "northup"  : __DIR__"zizhiyu",
]));
        set("no_clean_up", 0);
        set("outdoors", "hengshan");	
        set("cost", 1);	
        setup();
        replace_program(ROOM);
}

