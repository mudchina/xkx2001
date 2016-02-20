//Cracked by Roath
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "厨房");
        set("long", @LONG
这里是供应全寺膳食的所在，几个油光满面的喇嘛正在忙碌，旁边有几个附
近请来帮手的居民。
LONG
        );
        set("exits", ([
                "west" : __DIR__"zoulang",
        ]));
	set("objects", ([
		__DIR__"npc/xlama2" : 1,
		__DIR__"obj/buttertea" : 3,
	]));


	set("cost", 0);
        setup();
        set("outdoors","qilian-shan");
}
int valid_leave(object me, string dir)
{

        if( dir == "west" && present("tea", me) )
        {
                return notify_fail("别着急，喝完茶再走 !\n");
        }
        return ::valid_leave(me, dir);
}
