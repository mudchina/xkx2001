//Cracked by Roath
// Room: /d/dali/wangfu1.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", RED"王府大门"NOR"：");
	set("long","你正站在一座豪华的府门前，门前有两只极大的石狮子，门上高悬一块横匾，
上书"HIY"「平南王府」"NOR"四个金字。门口站着两排侍卫，身着锦衣，手执钢刀，气宇轩
昂。褚万里气宇轩昂地站在侍卫中间，目光如炬地打量着从这里经过的行人。\n"
);
	set("objects", ([
		__DIR__"npc/weishi1" : 1,
		__DIR__"npc/weishi2" : 2,
		"/kungfu/class/dali/zhuwanli" : 1,
		]));
	set("exits", ([
		"east" : __DIR__"dalicheng1.c",
		"enter" : __DIR__"wangfu2.c",
		]));
	set("cost", 1);
	set("wangfu", 1);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	set("outdoors", "dali");
	set("valid_startroom",1);
	setup();
	"/clone/board/dali_b"->foo();
}
void init()
{
	object me;
	if (interactive(me = this_player())
		&& me->query("family/family_name")=="大理段家"
		&& !me->query("dali/employee"))
	{
		me->set("dali/employee",1);
		me->set("dali/trust",100);
	}
}
int valid_leave(object me, string dir)
{
	object ob;
	if (me->query("family/family_name")!="大理段家"
		&& !me->query("dali/employee")
		&& dir == "enter"
		&& living(ob=present("zhu wanli", environment(me))))
	return notify_fail("褚万里喝道：闲杂人等，不得入内。\n");
	return ::valid_leave(me, dir);
}
