//Cracked by Roath
// Summer 9/25/96
#include "room.h"
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "大雪山");
        set("long", @LONG
群山环绕，四周积雪终年不化。南边不远处有一个山谷。
LONG
        );
        set("exits", ([
                "eastdown" : __DIR__"xshan1",
		"southup" : __DIR__"shangu",
        ]));
	set("objects", ([
                "/d/qilian/npc/caiyaoren": 1,
        ]));



	set("cost", 4);
	set("bing_can", 2);
        setup();
        set("outdoors","qilian-shan");
}
int valid_leave(object me, string dir)
{
	object *ob;
        int i;

        if( dir == "southup" && random((int)me->query_skill("dodge")) <= 10){
        
                message_vision(HIW"突然轰隆一声巨响，$N脚下踏了个空，... 啊...雪崩了！\n"NOR, me );
          	ob = all_inventory(environment(me));
		for(i=0; i<sizeof(ob); i++) {
                if( !userp(ob[i]) ) continue;

		if (random(15) == 1)
                me->move(__DIR__"shangu3");
	
		else
		ob[i]->move(__DIR__"shankou");

		ob[i]->receive_damage("qi", 100, "被雪崩活埋了");
		ob[i]->receive_wound("qi", 70, "被雪崩活埋了");
		message("vision", HIW"只见" + ob[i]->query("name")
 + "飞也似地从山顶上奔下来，但是被一个大雪球当头砸住，啊。。。前面雪崩了！\n"NOR, environment(me), me);
		
		}
                return notify_fail(HIW"只见大片的积雪从山峰上奔腾而下，向你铺天盖地地扑过来，沿途并夹带了不少岩石。赶紧逃命吧！\n"NOR);
        }
	return ::valid_leave(me, dir);
}

