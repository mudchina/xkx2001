//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "羊肠小路");
        set("long", @LONG
眼前是一条一条羊肠小路，地处越来越偏僻，路径越来越隐秘。
LONG
        );
        set("exits", ([
                "east" : __DIR__"xiaolu"+(random(5)+4),
                "north" : __DIR__"xiaolu6",
                "west" : __DIR__"xiaolu7",
		"south" :__DIR__"danfeng",
        ]));


	set("cost", 1);
        setup();
        set("outdoors","qilian-shan");
}
int valid_leave(object me, string dir)
{
                me->move(__DIR__"aili");
		message("vision", me->query("name") + "神经兮兮地走了过来。\n", environment(me), me);
		return notify_fail("你迷迷糊糊不知不觉地走进了流沙群。 \n");
}
