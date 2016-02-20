//Cracked by Roath
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "翠屏峰悬空寺");
        set("long", 
"为北岳恒山第一奇观，自下仰望，但见飞阁二座，耸立于
翠屏峰顶，宛似仙人楼阁，现于云端。两座飞阁皆高三层，
凌虚数十丈，相距数十步，两楼以飞桥相连。\n");
        
set("exits", ([
                "westup"  : __DIR__"shenshege",
                "eastup"   : __DIR__"lingguige",
                "westdown" : __DIR__"ciyaokou",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "hengshan");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

