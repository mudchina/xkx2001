//Cracked by Roath
// 
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{   
   set("short", "");
   set("long", @LONG

LONG        );

   set("item_desc", 
    	   ([
      	"item1" : 
		"des1\n"
      	"item2" :
		"des2\n"
   	   ])
	);
   set("exits", ([ /* sizeof() == 1 */ 
                  "east" : __DIR__"yuelang", 
                ])
       );
   setup();
   replace_program(ROOM);
}

void init()
{
   add_action("do_action1","action1");
}

int do_action1(string arg)
{
}

