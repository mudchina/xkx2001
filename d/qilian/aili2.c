//Cracked by Roath
// Summer 9/12/96
#include "room.h"
#include <ansi.h>
inherit ROOM;

void create()

{
        set("short", "爱力生");
        set("long", @LONG
这里是一遍流沙。抬眼望去，黄茫茫一片沙漠，似无尽头，直连天边，
一不留神踏入，就石牛入海，消失得无影无踪了，蒙古语称为爱力生。
LONG
        );
        set("exits", ([
                "north" : __DIR__"aili3",
                "west" : __DIR__"aili",
		"south" : __DIR__"aili3",
		"east" : __DIR__"aili3",
        ]));


        set("outdoors","qilian-shan");
	set("cost", 5);
        setup();
}
int valid_leave(object me, string dir)
{
	if( random((int)me->query_skill("dodge")) <= 5)
	{
		me->receive_wound("qi", 300, "被流沙活埋了");
		message_vision(HIY"$N的身子被流沙吸住了。 \n"NOR, me);
	}
        else {
                me->receive_damage("qi", 200, "被流沙活埋了");
                me->receive_wound("qi",  100, "被流沙活埋了");
                message_vision(HIY"$N的双脚在慢慢地陷进流沙里。\n"NOR, me );
	}
	return ::valid_leave(me, dir);
} 
