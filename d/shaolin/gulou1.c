//Cracked by Roath
// Room: /d/shaolin/gulou1.c
// Date: YZC 96/01/19

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "鼓楼一层");
	set("long", @LONG
这里是塔楼的底层，一缕缕阳光从墙上的花砖缝隙里透射
进来，在青砖地上投下别致的光影，如同一格格棋盘相似。往
上看，长长的木楼梯盘绕而上，似乎永无尽头。墙角，梯级都
相当洁净，看来经常有僧人打扫。
LONG
	);

	set("exits", ([
		"up" : __DIR__"gulou2",
		"out" : __DIR__"gulou",
	]));

	set("objects",([
		"kungfu/class/shaolin/jue-xin" : 1,
	]));
	set("cost", 2);
	setup();
}

void init()
{
	object me, ob;
	int i;

	me = this_player();

	if( !userp(me) ) return;

	if( (me->query("family/family_name") != "少林派"
	||  me->query("family/generation") > 36
	||  me->query_temp("win_times") < 3)
	&& me->query( "family/master_name") != "觉心" ) {
		if( objectp(ob = present("juexin", this_object())) )	
			destruct(ob);
		else {
			remove_call_out("make_juexin");
//			call_out("make_juexin", random(600));
			call_out("make_juexin", 1);
		}
	} else {
		if( !objectp(ob = present("juexin", this_object())) ) {
			remove_call_out("make_juexin");
//			call_out("make_juexin", random(600));
			call_out("make_juexin", 1);
		}
		else call_out("dest_juexin", random(600), ob);
	}	

	for( i=1; i<10; i++) {
		if( objectp(ob = present("juexin 2", this_object())) )	
			destruct(ob);
	}
}

int make_juexin()
{
	object ob;

	ob=new("/kungfu/class/shaolin/jue-xin");
	ob->move("/d/shaolin/gulou1");
	message_vision(HIW "\n觉心大师走了过来，盘腿坐下，向你微笑著点点头，开始入定。\n" NOR, ob); 
	call_out("dest_juexin", random(600), ob);
	return 1;
}

int dest_juexin(object ob)
{
	if (!ob) return 1;
	message_vision(HIW "\n觉心大师站起身，挥了挥手，往上离开。\n" NOR, ob); 
	remove_call_out("make_juexin");
	//call_out("make_juexin", random(600));
	destruct(ob);
	return 1;
}


