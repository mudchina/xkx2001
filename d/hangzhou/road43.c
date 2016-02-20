//Cracked by Roath
// 土路
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
   set("short", "土路");
   set("long", @LONG
路旁一条小溪。溪水哗哗地流着，不时有鱼儿(fish)跃出水面。
溪旁几各男孩正低着头专心在钓鱼。
LONG
       );
   set("item_desc", 
    	   ([
      	"fish" : 
		"“哗”一条大鱼跃水而出，“噗”的一声又掉回水里。渐得男孩一身水。\n",
   	   ])
	);

   set("exits", ([ /* sizeof() == 2 */ 
                  "northeast" : __DIR__"road42", 
                  "southwest" : __DIR__"road62", 
                ])
       );
                set("objects", ([ "/d/village/npc/boy" : 2]));

   setup();
   replace_program(ROOM);
}
