//Cracked by Roath
// group /d/bwdh/sjsz/wzoulan
// sdong, 8/8/99

#include <ansi.h>
inherit ROOM;
#include "sjsz_room.h"

void create() {
	 set("short", HIG"小道"NOR);
	 set("long", @LONG
这里是一条林中小道，寂静得让人害怕。
LONG
	 );
	 set("exits", ([
						"south" : __DIR__"wgarden",
						"east"  : __DIR__"room_02",
								 ]));
    set("outdoors", "city");
	 create_room();
	 setup();
}

void init() {
	 init_room();
}
