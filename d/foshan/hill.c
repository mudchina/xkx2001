//Cracked by Roath
//Jay 4/7/96

#include <room.h>

inherit ROOM;
int do_bocao(string);

void create()
{ 
       set("short","山丘");
       set("long", @LONG
这里是村外的一个小山丘。到处是荒草没没。秋风吹过，
发出飒飒之声。
LONG
     );
        set("exits", ([
                "northdown" : __DIR__"cunkou",
        ]));       

        set("objects", ([
		"/d/wudang/npc/yetu" : 2,
	]));
	set("outdoors", "wudang");
	set("cost", 1);
        setup();
}

void init()
{
        add_action("do_bocao", "bocao");
}


int do_bocao(string arg)
{
	object me = this_player();
	if (me->query_temp("qi/bocao")) {
        message_vision("$N拨开荒草，草后露出一个山洞。\n", me);
        set("exits/enter", __DIR__"cave");
        remove_call_out("close");
        call_out("close", 5, this_object());
        return 1;
	}
	return 0;
}

void close(object room)
{
        message("vision","一阵秋风吹过，洞口又看不到了。\n", room);
        room->delete("exits/enter");
}
 
