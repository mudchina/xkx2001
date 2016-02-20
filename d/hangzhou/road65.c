//Cracked by Roath
 // 满觉陇
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{   set("short", HIM"满觉陇"NOR);
    set("long", @LONG
山路旁有一个小村落，村落四周桂花成林。每当仲秋，桂花盛开，
飘香数里。被称为“金雪世界”。西上是水乐洞，东下石屋洞。
LONG);

    set("exits", ([ /* sizeof() == 2 */ 
                  "westup" : __DIR__"road64", 
                  "eastdown" : __DIR__"road66", 
                ])
       );
	set("cost", 2);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}
