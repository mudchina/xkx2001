//Cracked by Roath
// sdong, 3/18/2000

#include <ansi.h>
inherit ROOM;
#include "sjsz_room.h"

void create()
{
        set("short","炮台");

        set("long",@LONG
这里居然是一座高高的炮台，真是令人难以置信。从这里可以看到试剑山庄
的每一个角落，但见红砖青瓦，风光无限。可是其中掩藏的杀机，却令人不寒而
栗。众武林高手，一声不坑地严阵以待。
LONG);

          set("exits",([ 
                         "down" : __DIR__"etower6",
                      ])
              );
	    set("objects", ([
		  __DIR__"obj/pao"     : 1,
		  __DIR__"obj/huoyao"     : 2,
		  __DIR__"obj/dantou"     : 5,
		 ]));
          set("cost",3);
          set("outdoors", "city");
	create_room();
          setup();
}

void init()
{
        init_room();
}

