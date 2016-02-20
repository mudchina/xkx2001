//Cracked by Roath
// group bwdh/room 09
// 

#include <ansi.h>
inherit ROOM;
#include "sjsz_room.h"

void create() {
	 set("short", HIW"山道"NOR);
	 set("long", @LONG
这里是一条陡峭的山道，通望险峻的山峰。这里地势险要，真是一关把道，万夫莫行。
东边通往啸云虎坛，是众兵把守的机要之地。
LONG
    );
    set("exits", ([
        "west"      : __DIR__"room_07",
        "east"      : __DIR__"etang",
	 ]));
    create_room();
	 setup();
    message("vision","大门嘭的一声，自动关上了！",this_object());
}

void init() {
	 init_room();
}
