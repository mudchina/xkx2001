//Cracked by Roath
// /d/xueshan/dumudian.c
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "度母殿");
        set("long", @LONG
这里是大轮寺的度母殿，正中五尊大座佛，均为高肉髻、外披
袒右袈裟、结跏趺坐、执手印须弭坐各异。殿内对称排列四根大柱，
上雕忍冬纹，下刻连珠纹。北壁上供有两尊金刚像：马头明王和阎
魔护法。
LONG
        );
        set("exits", ([
				"north" : __DIR__"changlang",
                "southdown" : __DIR__"yanwu",
        ]));
	set("objects", ([
		__DIR__"npc/zrlama": 1,
		__DIR__"obj/tonggang": 1,
	]));

	set("cost", 1);
    setup();
}

void reset()
{
	::reset();
	set("no_clean_up", 1);
}
