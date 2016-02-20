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
每当盛夏，游客到此纷纷寻荫小息，堤上绿树交柯，鸣蝉噪鼓。
北边是望山桥，南面锁澜桥。
LONG        );

   set("exits", ([ /* sizeof() == 2 */ 
                  "south" : __DIR__"suti6", 
                  "north" : __DIR__"suti4", 
                ])
       );
	set("cost", 1);
        set("outdoors", "hangzhou");
   setup();
   replace_program(ROOM);
}