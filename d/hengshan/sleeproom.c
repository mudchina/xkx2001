//Cracked by Roath
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "卧房");
        set("long", 
"房内静悄悄的，窗帘合着，光线昏暗，屋左边一字排开摆着
若干张卧榻，几个恒山弟子正在休息。\n"
        );
        set("exits", ([
                "east"  : __DIR__"jingshi",
]));
        set("no_clean_up", 0);
        set("sleep_room", "1");
        set("no_fight", "1");
        setup();
        replace_program(ROOM);
}

