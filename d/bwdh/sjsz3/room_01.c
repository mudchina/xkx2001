//Cracked by Roath
// group bwdh/room 01
// Apache 09/27/98

#include <ansi.h>
inherit ROOM;
#include "sjsz_room.h"

void create() {
	 set("short", HIG"草地"NOR);
	 set("long", @LONG
这里是一大片空旷的草地。在明媚的阳光照耀下，空气中洋溢着平和的气氛。
西边通往赤火龙坛，却是猛将云集的地方。
LONG
    );
    set("exits", ([
        "east" : __DIR__"room_03",
        "west" : __DIR__"wtang",
	 ]));
    create_room();
    setup();
}

void init() {
    init_room();
}
