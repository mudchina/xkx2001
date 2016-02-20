//Cracked by Roath
// 苏堤
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", "苏堤");
   set("long", @LONG
寒冬，瑞雪霏霏中，不少游人踏雪观景。从堤上极目远眺，只见
四周玉树琼林。北边是东浦桥，南面是压堤桥。
LONG        );

   set("exits", ([ /* sizeof() == 2 */ 
                  "south" : __DIR__"suti4", 
                  "north" : __DIR__"suti2", 
                ])
       );
	set("cost", 1);
        set("outdoors", "hangzhou");
   setup();
   replace_program(ROOM);
}