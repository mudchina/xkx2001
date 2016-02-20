//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "夏拉");
        set("long", @LONG
抬眼望去，黄茫茫一片沙漠，似无尽头，直连天边。这里尽是
黄沙石砾，没有一点生气，蒙古语称为夏拉。
LONG
        );
        set("exits", ([
                "east" : __DIR__"xiala2",
                "south" : __FILE__,
		"north" :__DIR__"xiala2",
		"west" :__DIR__"xiala4",
        ]));


	set("cost", 5);
	set("outdoors","qilian-shan");
        setup();
}
int valid_leave(object me, string dir)
{
	object *ob;
	int i;

        if ( dir == "south")
            me->add_temp("mark/steps",-1);

	if (me->query("ridable"))
            me->delete_temp("mark/steps");

	if( !me->query("rided") && me->query("id") != "camel"){
            me->add("jingli", -70);
            me->add("water", -70);
        if(me->query("water") < 0)
            me->set("water", 0);
        }
     if (me->query_temp("mark/steps") == -3)
            {
	ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++){
        if( ob[i]->query("rider") == me )
        ob[i]->move("/d/qilian/gebi7");
	}
	 me->move("/d/qilian/gebi7");
           me->delete_temp("mark/steps");
         return notify_fail("你走出了夏拉。\n");
}
 return ::valid_leave(me,dir);
}
