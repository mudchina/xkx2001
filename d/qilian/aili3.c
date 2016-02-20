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
                "west" : __DIR__"aili",
        ]));


	set("cost", 5);
        setup();
        set("outdoors","qilian-shan");
}
int valid_leave(object me, string dir)
{
	object *inv;
	int i;
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
                        if(inv[i]->query("id") == "tie lian")continue;
			if(inv[i]->is_character() ) 
			inv[i]->recieve_wound("qi", 3000, "被流沙活埋了");
		destruct(inv[i]);
		}
		me->move(__DIR__"xiaolu");
                me->unconcious();
	return notify_fail(HIY"你的身子被流沙吸住到处游走，你感觉不行了。 \n"NOR);
} 
