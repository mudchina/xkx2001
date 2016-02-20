//Cracked by Roath
// group bwdh/room 28
// sdong 10/03/98

#include <ansi.h>
inherit ROOM;
#include "sjsz_room.h"

void create() {
	 set("short", HIB"地下室"NOR);
	 set("long", @LONG
这地下室光线暗淡，花岗石地上血迹斑斑，到处是刀、
剑的砍痕。有的地方还有脚印，显然是内功极深的人印上
的。空气中渗透着血腥气和腐尸味，使你受到异常的刺激，
禁不住血脉忿张。
LONG
	 );
	 set("exits", ([
		  "up"      : __DIR__"room_28",
		  "north"   : __DIR__"room_30",
	 ]));
    create_room();
    set("objects", ([
		  __DIR__"npc/master2" : 1,
	 ]));
    setup();
}

void init() {
    init_room();
}
