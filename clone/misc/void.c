//Cracked by Roath
// void.c (re-created after Elon screwed it up on 07-24-95)
#include <login.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","最後乐园");
	set("long",@LONG	
这里就是传说中的 VOID -- 大神和巫师的最後乐园。你看到四周一片
白茫茫的，不一会从虚无中冒出一只企鹅，递给你一罐「可口可乐」(tm)，
然後站在一旁很邪恶地笑著。又过了一会，一只北极熊走了过来，一掌拍扁
了那只企鹅并从你手上抢走那瓶可乐，大笑三声後就从你眼前消失了。
你摇摇头，这种地方还是不要待太久的好。
LONG
	);

	set("exits", ([
		"down" : "/d/city/zuixianlou",
	]));
	set("no_clean_up", 1);
	set("no_fight",1);
	setup();
//	replace_program(ROOM);
}
void init()
{       
	object me = this_player();
	if (me->query("startroom")== "/d/death/blkbot")
		{
		write(HIW "\n天网恢恢，疏而不漏，你还是等巫师放你把！\n\n" NOR);
		me->move("/d/death/blkbot");
		me->set("startroom", "/d/death/blkbot");
		return 0;
        }
		return 0;
}
