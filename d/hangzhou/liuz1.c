//Cracked by Roath
// 刘庄
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", "刘庄");
   set("long", @LONG
庄园的大匾上是“刘庄”两个大字。大门(gate)紧闭，里面静悄
悄的一点声音都没有。
LONG
      );

   set("item_desc", 
    	   ([
      	"gate" : 
		"朱红的大门紧闭着，敲敲(knock)看吧。\n"
   	   ])
	);

   set("exits", ([ /* sizeof() == 1 */ 
                  "east" : __DIR__"road54", 
                ])
       );
	set("objects", ([
                "/d/city/npc/guanjia" : 1,
                "/d/city/npc/jiading" : 2,
	]));
   setup();
}
void init()
{
   add_action("do_knock","knock");
   add_action("do_knock","敲");
}

int do_knock(string arg)
{  
   if( !arg || arg=="" ) return 0;
   if( arg=="gate" || arg=="门")
   {			
	message_vision("$N “咚，咚，咚，。。。”地敲着门，可里面却一点动静都没有。\n", this_player());
	return 1;
   }
}

