//Cracked by Roath
// Room: /d/shaolin/wuqiku.c
// Date: YZC 96/01/19

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "武器库");
	set("long", @LONG
少林寺的武器库可称天下第一，十八般兵器，这里可谓应有
尽有。四面一望，令你顿感眼花缭乱。墙上砌了一个个小格子，
每个都插满了各种各样的兵器。墙角一个健壮的僧人正乒乒乓
乓地在打造一根禅杖。另一位灰衣僧人正在墙角拂拭一把戒刀。
看到你进来，他缓缓起身，向你迎了过来。
LONG
	);

	set("exits", ([
		"west" : __DIR__"zhulin2",
		"north" : __DIR__"fangjuku",
	]));

	create_door("west","木门","east",DOOR_CLOSED);
	set("objects",([
		CLASS_D("shaolin") + "/dao-chen" : 1,
		__DIR__"npc/datie-seng" : 1,
		__DIR__"obj/zhujian" : 1,
		__DIR__"obj/mudao" : 1,
	]));
	set("cost", 1);
	setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_kill", "kill");
}

int do_kill(string arg)
{
	object ob, me=this_player();

	if ( arg == "daochen chanshi" || arg == "daochen" || arg == "chanshi" ) {
		if ( !ob=present(arg, environment(me)) ) return 0;

		message_vision("$N对著道尘禅师喝道：「死秃驴！今日不是你死就是我活！」\n", me);
		me->kill_ob(ob);
		
		message_vision("$N一声冷笑，伸手在墙上一按，地上突然裂开一个大洞，$n意料之余跌了下去！\n", ob, me);
		me->move("/d/shaolin/jianyu.c");
		tell_object(me,"你跌入陷阱，直落到少林寺的监狱里！\n");

		return 1;
	}

	return 0;
}
