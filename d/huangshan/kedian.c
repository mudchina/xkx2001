//Cracked by Roath
// 北海客店
// Dong  1/20/1996.

// NTD:  NPC and object. 伙计。

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{   set("short", "北海客店");
    set("long", @LONG
这家客建在这里是为了方便那些浏涟忘返的游客。里面的装饰古
朴，伙计也十分热情。
LONG);

    set("exits", ([ /* sizeof() == 1 */ 
                   "out" : __DIR__"beihai", 
                 ])
       );

    setup();
    replace_program(ROOM);
}