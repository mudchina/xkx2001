//Cracked by Roath
// group bwdh/room 30
// sdong 10/03/98

#include <ansi.h>
inherit ROOM;
#include "sjsz_room.h"

void create() {
	 set("short", BLU"地下室"NOR);
	 set("long", @LONG
这地下室光线暗淡，地上铺了很多冰块，血迹斑斑，空气中
渗透着血腥气和腐尸味，使你受到异常的刺激，禁不住血脉忿张。
LONG
	 );
	 set("exits", ([
		  "south"      : __DIR__"room_29",
	 ]));
	 create_room();
	 set("objects", ([
		  __DIR__"obj/box" : 1,
	 ]));
    setup();
}

void init() {
    init_room();
}
