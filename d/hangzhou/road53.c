//Cracked by Roath
// 丁家山
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", "大路");
   set("long", @LONG
路的东边是一座小山。山上郁郁葱葱，种满了树。山上本是一处
观赏西湖的好地方，但却被丁财主占为私有。大路向东北和南延伸。
LONG
      );

   set("exits", ([ /* sizeof() == 2 */ 
                  "northeast" : __DIR__"road52", 
                  "south" : __DIR__"road54", 
                ])
       );
	set("objects",([
                "/d/taishan/npc/tiao-fu" : 1,
        ]));   
	set("cost", 1);
        set("outdoors", "hangzhou");
   setup();
   replace_program(ROOM);
}
