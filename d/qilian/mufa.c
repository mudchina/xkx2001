//Cracked by Roath
// Summer 9/25/96
#include "room.h"

inherit ROOM;
int do_rowing();
void create()
{
        set("short", "木筏上");
        set("long", @LONG
你站在木筏上摇摇摆摆地慢慢向前划(rowing)，河水不时溅起来，把你衣裳
都弄湿了。
LONG
        );

	set("cost", 2);
        setup();
        set("outdoors","qilian-shan");
}
void init()
{
   add_action("do_rowing","rowing");
}
int do_rowing()
{
    object ob, me = this_player();
    int check, wait_time = 0;
    remove_call_out("open_up");
    message_vision("$N使劲地把木筏向前划呀！划呀！\n", me);
    me->receive_damage("jingli", 15, "落水淹死了");
    me->set_temp("marks/划", 1);
    if ( me->query_temp("marks/划") && interactive(me) && !me->is_fighting()) {
           call_out("open_up", random(10)+10, me);
        }
    return 1;
}
int open_up(object me)
{
        message_vision("$N划了半天，木筏终於靠岸了。\n", me);
        set("exits/up", __DIR__"sulew");
	call_out("close_up", 3, me);
           remove_call_out("open_up");
	this_player()->delete_temp("marks/划 ");
	return 1;
}
int close_up(object me)
{
        message_vision("木筏又被冲到河中央去了。\n", me);
        delete("exits/up");
        this_player()->delete_temp("marks/划 ");
	remove_call_out("open_up");
        return 1;
}
