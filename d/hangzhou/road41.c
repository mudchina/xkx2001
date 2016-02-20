//Cracked by Roath
//  黄泥岭
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "黄泥岭");
    set("long", @LONG
一条黄土路弯弯曲曲，四周非常的安静。偶而才看见些游人匆匆而过。
南北分别是下山的路。
LONG
        );

    set("exits", ([ /* sizeof() == 2 */ 
                  "northdown" : __DIR__"road32", 
                  "southdown" : __DIR__"road42", 
                 ])
        );

	set("cost", 3);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}