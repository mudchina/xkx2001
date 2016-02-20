//Cracked by Roath
// 玉皇山路
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	int i;
   set("short", "山路");
   set("long", @LONG
山路崎岖，曲折蜿延。四周林木苍翠，修竹茂密。山路旁有一山
洞，据说洞里有时会传出虎哮声，故名老虎洞。西边是下山的路，往
东下山便到了山底。
LONG
        );

   set("exits", ([ /* sizeof() == 2 */ 
                  "westdown" : __DIR__"yuhuang5", 
                  "eastup" : __DIR__"yuhuang3", 
                ])
       );
	i = random (3);
        switch (i) {
        case 0:
        set("objects", ([
            "/d/city/obj/branch1" : 1,
            "/d/city/npc/maque" : 1,
        ]));
	break;
	case 1:
        set("objects", ([
            "/d/city/obj/branch1" : 1,
            "/d/wudang/npc/yetu" : 1,
        ]));
	break;
        case 2:
	set("objects", ([
            "/d/city/obj/branch2" : 1,
            "/d/city/npc/laohu" : 1,
        ]));
	break;
	}
	set("cost", 2);
        set("outdoors", "hangzhou");
   setup();
   replace_program(ROOM);
}
