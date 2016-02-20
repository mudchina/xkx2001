//Cracked by Roath
// 一线天
// Dong  01/20/97.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "一线天");
    set("long", @LONG
石缝中，阴森森的凉气从脚下侵入，行至中途，真令人担心两石
会突然合在一起，把人挤成肉泥。仰面往上看，一缕阳光到射下来，
像一柄金色宝剑，无边无垠的蓝天，被挤成一条又细又长的蓝线。
LONG);

    set("exits", ([ /* sizeof() == 2 */
	"south" : __DIR__"yixian1",
	"north" : __DIR__"penglai",
		 ])
	 );
    setup();
    replace_program(ROOM);
}
void init()
{
   add_action("do_ji","ji");
   add_action("do_ji","挤");
}

int do_ji(string arg)
{
}
