//Cracked by Roath
// room: /d/baituo/base1
// 白驼改版
// maco 2/17/2000
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "密窖");
        set("long", @LONG
这里伸手不见五指，只能听到唏唏嗦唢爬虫蠕动的声音。
LONG
        );
        set("exits", ([ 
	    "up" : __DIR__"lingshege",
	    "north" : __DIR__"base2",
        ]));
        set("objects", ([ 
	    __DIR__"npc/snake" : 3,
		"/d/foshan/npc/zsnake" : 2,
         ]) );
        replace_program(ROOM);
	create_door("up", "密窖石门", "down", DOOR_CLOSED);
	set("cost", 0);
        setup();
}
