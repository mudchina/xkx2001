//Cracked by Roath
// Write by Wzfeng@xkx 2000 3-2 
// Modified by Sure 9/2000
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIM"鲜花店"NOR);
                set("long", @LONG
这里是新近开张的一家鲜花店，店内百花齐放，清香满室。花儿虽非名种，
却也朵朵娇艳欲滴。她们是期待、是问候、是默默的祝福、是深深的思念……
小姑娘英莲手持花洒，在花间轻轻走动，精心照料着每朵鲜花。门边柜台上还
立着一张告示(gaoshi)。
LONG
        );
        
        set("no_fight", 1);
        set("exits", ([
                       "east" : __DIR__"kedian",
                        ]));
             set("item_desc", ([
                        "gaoshi":
                    "┌──────────────"+HIG"购花须知"NOR+"─────────────────┐\n"
                        "│ 一：花店里花儿的价格用（list)查看，买花可直接向店主购买（buy)        │ \n"
                        "│ 二：本鲜花店提供送花，详情请向买花女查询(ask ying lian about songhua)│ \n"
                        "│ 三：请用(help flower)来查询花朵含义和资料。                          │ \n"
                        "└───────────────────────────────────┘ \n\n"
                        ]) );
        set("objects", ([
                __DIR__"npc/hua_girl" : 1,
        ]));
            set("no_fight",1);
            set("no_sleep",1);
            setup();

}
