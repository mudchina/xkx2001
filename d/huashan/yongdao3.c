//Cracked by Roath
// 华山甬道
// qfy 16/10/1996

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "甬道");
	set("long", @LONG
这是山腹内的一条裂缝所形成的狭窄的甬道。十几丈远处，甬道渐高
，可挺起身来行走。甬道尽头转向右边，使人无法预知甬道后是什么。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
		"right" :  __DIR__"jinshe1",
		"out" : __DIR__"cliff",
	]));
	   
	set("cost", 1);
	setup();
}

int valid_leave(object me, string dir)
{
	object room1, room2;

	if ( present("skeleton", me) && dir == "out" )
		return notify_fail("你想带着骸骨到那儿去呀？\n");

	if ( !( room1 = find_object(__DIR__"jinshedong") ) )
		room1 = load_object(__DIR__"jinshedong");

	if ( !( room2 = find_object(__DIR__"jinshe1") ) )
		room2 = load_object(__DIR__"jinshe1");

	if ( dir == "out" && !me->query_temp("buried") && me->query_temp("visited") &&
	(present("skeleton", room1) || present("skeleton", room2) || present("skeleton", environment(me)) ) ) 
		call_out("poison", 10, me);

	me->delete_temp("buried");
	me->delete_temp("visited");

	return ::valid_leave(me, dir);
}

int poison(object me)
{
	tell_object(me, HIR "你一口气透不过来，原来在金蛇洞里中了毒，现在发作了！\n" NOR);
	me->receive_wound("qi", me->query("max_qi")+100, "毒气攻心死了");

	return 1;
}
