//Cracked by Roath
// 天竺山路
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", "山路");
   set("long", @LONG
一条被人走出来的山路，弯弯曲曲地向上延伸。走在山路上，只
见两旁峰峦秀丽，景色怡人。不时有进香客擦肩而过。南上便到了下
天竺。北下就是大道。
LONG
        );

   set("exits", ([ /* sizeof() == 2 */ 
                  "southup" : __DIR__"tianzhu1", 
                  "northdown" : __DIR__"road33", 
                ])
       );

	set("cost", 2);
        set("outdoors", "hangzhou");
   setup();
   replace_program(ROOM);
}