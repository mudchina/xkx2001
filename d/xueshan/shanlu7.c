//Cracked by Roath
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
这里是靠近川西的崇山峻岭，怪石嶙峋。再往东去就是川西边缘了。
往西有一座雪山高耸入云。路边上有一个大雪坑(hollow)。
LONG
        );
        set("exits", ([
                "northdown" : __DIR__"shanlu6",
		"westup" : __DIR__"shankou",
		"eastdown" : "/d/emei/chuanxi2",
        ]));
	set("item_desc", ([
	"hollow" : "一个雪坑，似乎可以跳(jump)下去。\n",
	]));
	set("objects", ([
                __DIR__"npc/liu" : 1,
        ]));

	set("cost", 3);
        setup();
        set("outdoors","qilian-shan");
}
void init()
{
        add_action("do_jump", "jump");
}
int do_jump(string arg)
{
	int i;
	object me, *ob;
        me = this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="hollow"){
        message_vision("$N刚想往下跳，脚在雪地上一滑，卞叽一下摔到坑底。\n", me);
                        message("vision",
        me->name() + "脚下一滑，卞叽一下摔不见了。\n",
                                environment(me), ({me}) );
		ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++){
        if( ob[i]->query("rider") == me )
        ob[i]->delete("rider");
	me->delete("rided");
	}
                        me->move("/d/qilian/underxs");
                        message("vision",
                                me->name() + "突然卞叽一声从上面摔到坑里。\n",environment(me), ({me}) );
	return 1;
	}
}
