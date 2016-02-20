//Cracked by Roath
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "羊肉馆");
        set("long", @LONG
这是兰州城内最大的羊肉馆，卖的全是从城外草原上拉来的
刚宰杀的活羊，又鲜又嫩。南来北往的客商，到此地打尖，无不
到这儿来尝尝鲜。更有不少附近寺院的喇嘛到这儿偷腥。
LONG
        );
        set("exits", ([
                "south" : __DIR__"weststreet",
        ]));
	set("objects", ([
                __DIR__"npc/xiaoer2": 1,
	]));
	set("cost", 1);
        setup();
        replace_program(ROOM);
}    
