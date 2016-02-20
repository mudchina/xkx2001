//Cracked by Roath
// sdong, 3/18/2000

#include <ansi.h>
inherit ROOM;
#include "sjsz_room.h"

void create()
{
        set("short","石阶");

        set("long",@LONG
这後山石阶蜿蜒於试剑山庄中，也不知通往何处。只见浓荫蔽天，越
走越是阴森，不时还有野兽吼声传来，令人心中发毛。
LONG);

          set("exits",([ "up" : __DIR__"etower2",
                         "down" : __DIR__"room_09",
                      ])
              );
          set("cost",2);
	create_room();
          setup();
}

void init()
{
        init_room();
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        object wp, *inv;
        int i, j=0;

        if ( dir == "up" )
        {
			inv = all_inventory(this_object());
    
			for (i = 0; i < sizeof(inv); i++)
				if ( objectp(inv[i]) && living(inv[i]) && (inv[i]->query("sjsz/team_name") != me->query("sjsz/team_name")) && inv[i]->query("id") !="sheying shi" )
                {
                        j++;
                        if (objectp(wp = inv[i]->query_temp("weapon")))
                                message_vision("$N对$n喝道：尔等邪魔歪道人物，要想过此路，得先问问我手中的"
                                + wp->query("name")+ "答应不答应！\n", inv[i], me); 
                        else 
                                message_vision("$N对$n喝道：只要我在，尔等邪魔歪道人物，便休想过此路！\n", inv[i], me);
                }
           
	        if (j) return notify_fail("\n");    
        }
        
        return ::valid_leave(me, dir);
}

