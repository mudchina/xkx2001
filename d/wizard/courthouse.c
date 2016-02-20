// Room: /d/wiz/courthouse.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "法院");
	set("long", @LONG
这里是侠客行的巫师审问机器人的法院，你一定是被人检举或是
行为太像机器人，才会来到这里，如果你答不出审判官的三个问题，会
被做上记号，超过三次的人将会被处以极刑，好好回答吧。
LONG
	);
	set("no_fight", 1);
	set("no_sleep_room",1);
	set("objects", ([
		__DIR__"npc/judge":1 ]) );

	set("cost", 0);
	setup();
}

void test_me(object me)
{
	me->set_temp("old_startroom", me->query("startroom"));
	me->set("startroom", __FILE__);
	me->set_temp("last_location", base_name(environment(me)));
	message_vision(HIW"忽然天上掉下副枷锁，正套中$N的脖子！接着伸出一只木制机械手，将$N牵走了¨¨\n"NOR, me);
	me->move(this_object());
}

