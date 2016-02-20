//Cracked by Roath
// 胡庆余堂
// Dong  11/03/1996.
// Buying medicine code needed here. !!!

// NTD:  NPC and object. 胡庆余，伙计。

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{   set("short", "胡庆余堂");
    set("long", @LONG
这是一家明净宽敞的药堂，後墙上是一个大药柜。几个伙计正忙
着爬上爬下地从小抽屉里抓药。药柜前摆着一张桌子，桌旁一位老者
正在为人把脉。他就是名医胡庆余。
LONG);

    set("exits", ([ /* sizeof() == 1 */ 
                   "west" : __DIR__"road25", 
                 ])
       );

	set("cost", 1);
    setup();
    replace_program(ROOM);
}