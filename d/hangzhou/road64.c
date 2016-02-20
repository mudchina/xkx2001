//Cracked by Roath
 // 水乐洞
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{   set("short", HIC"水乐洞"NOR);
    set("long", @LONG
水乐洞有两个洞口，洞的左口有股山泉从石缝中涌出。泉水声如
金石，和谐悦耳。旁有“天然琴声”，“听无弦琴”等石刻字句。洞
内两壁有很多钟乳石。往东是下山的路，西上便到了烟霞洞。
LONG);

    set("exits", ([ /* sizeof() == 2 */ 
                  "westup" : __DIR__"road63", 
                  "eastdown" : __DIR__"road65", 
                ])
       );
	set("cost", 2);
    setup();
    replace_program(ROOM);
}
