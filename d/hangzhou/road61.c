//Cracked by Roath
// 山路
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", "山路");
   set("long", @LONG
走在这弯弯的小路上，看着沿途山峰云影，松竹青葱，岩石斑驳。
不禁感到胸怀舒畅。西上便到了上天竺。东下就到了龙井。
LONG
       );

   set("exits", ([ /* sizeof() == 2 */ 
                  "westup" : __DIR__"tianzhu5", 
                  "eastdown" : __DIR__"road62", 
                ])
       );
   
	set("cost", 1);
        set("outdoors", "hangzhou");
   setup();
   replace_program(ROOM);
}