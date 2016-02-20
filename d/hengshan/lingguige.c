//Cracked by Roath
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "灵龟阁");
        set("long", 
"阁高三层，以插崖悬梁为基，巧借岩石暗脱，登此阁，步长
廊，跨栈道，钻天窗，曲折迂回，如临仙境，最高层中塑有释迦
牟尼，老子，孔子雕像。传说诗仙李白初见宣空寺，惊愕不已，
于阁内壁上书“壮观”两字。\n");
        
set("exits", ([
                "westdown"  : __DIR__"xuankongsi",
                "west"   : __DIR__"feiqiao",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "hengshan");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

