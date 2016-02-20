//Cracked by Roath
// Summer 9/25/96
#include "room.h"

inherit ROOM;
void create()
{
	int i;
        set("short", "塔底");
        set("long", @LONG
这儿是舍利塔底。四壁都是粗糙的岩片，墙脚燃着一盏长明灯，
照射出很微弱的光茫。四周灰尘厚积，蛛网密布。看来很少有人光
顾这儿。
LONG
        );
	set("invalid_startroom", 1);
 	i = random (9);
        switch (i) {
	case 0:
        set("objects", ([
            "/d/xueshan/obj/faling" : 1,
        ]));
	break;
        case 1:
        set("objects", ([
                "/d/xueshan/obj/klguan" : 1,
        ]));
	break;
	case 2:
        set("objects", ([
            "/d/city/obj/stone" : 1,
        ]));	
	break;
	case 3:
        set("objects", ([
            "/d/xueshan/obj/lubo" : 1,
        ]));
	break;
	case 4:
        set("objects", ([
		 "/d/xueshan/obj/fojing2" : 1,
        ]));
	break;
	case 5:
        set("objects", ([
            DRUG_D("sheli-zi") : 1,
        ]));
	break;
	case 6:
        set("objects", ([
            "/d/xingxiu/npc/snake" : 1,
        ]));
	break;
	case 7:
        set("objects", ([
		"/d/city/obj/branch2" : 1,
        ]));
        break;
	case 8:
        set("objects", ([
            "/d/shaolin/obj/book-stone" : 1,
        ]));
        break;
	case 8:
        set("objects", ([
            "/d/xueshan/obj/rtlian" : 1,
        ]));
        break;
	}
	set("exits", ([
                "out" : __DIR__"tower",
        ]));
	set("cost", 2);
        setup();
	
}
int valid_leave(object me, string dir)
{

        if( dir == "out" && present("sheli zi", me) )
        {
                return notify_fail("你不能把舍利子带走 !\n");
        }
        return ::valid_leave(me, dir);
}	
