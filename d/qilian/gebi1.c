//Cracked by Roath
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "戈壁");
        set("long", @LONG
抬眼望去，黄茫茫一片沙漠，似无尽头, 直连天边，本处沙土质潮，
地下尚有藏水，眼中仍可见些许枯黄沙草。永昌的驻军时有来此打个沙
兔、沙狼什么的。
LONG
        );
        set("exits", ([
                "north" : __FILE__,
                "south" : __DIR__"gebi4",
		"east" :__DIR__"gebi3",
		"west" :__DIR__"gebi2",
        ]));


	set("outdoors","qilian-shan");
	set("cost", 5);
        setup();
}

int valid_leave(object me, string dir)
{
	object *ob;
	int i;

        if ( dir == "north")
            me->add_temp("mark/steps",1);
        if ( dir == "south")
            me->add_temp("mark/steps",-1);
	if (me->query("ridable"))
	    me->delete_temp("mark/steps");
	if( !me->query("rided") && me->query("id") != "camel"){
            me->add("jingli", -50);
            me->add("water", -50);
        if(me->query("water") < 0)
            me->set("water", 0);
        }
        if (me->query_temp("mark/steps") == 6)
         {
	ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++){
        if( ob[i]->query("rider") == me )
        ob[i]->move("/d/qilian/gebi6");
	ob[i]->delete_temp("mark/steps");
	}
	me->move("/d/qilian/gebi6");
        me->delete_temp("mark/steps");
	 return notify_fail("你走进了沙漠深处。\n");
         }

        return ::valid_leave(me,dir);
}
