// By xuanyuan
// road: /zhongnan/lianggongshi2.c

inherit ROOM;
#include <ansi.h>
int do_study(string);

void create()
{
        set("short","练功室");

        set("long",@LONG
这石室和西边那石室是处处对称，ㄦ又处处相反，乃是北宽南窄，西圆东角,
室顶(shibi)也是刻满了无数符号.
LONG);

        set("item_desc",(["shibi" : "
据孙婆婆说，这石室就是本派始祖，林朝英，练武的地方。当年不知
为什麽，师祖在这古墓建了这一个石室，璧上所刻的尽是破解全真教武功
的绝招。
\n",]));

        set("exits",([ "west" : __DIR__"lianggongshi1",

                      ])
           );
	  set("cost",1);

        setup();

}

void init()
{
	add_action("do_study", "study");
	add_action("do_study", "du");
	add_action("do_study", "lingwu");
}

int do_study(string arg)
{
	object me;
        mapping fam;

	me = this_player();

	if ( !arg || arg != "shibi" )
		return notify_fail("什么？\n");

        if (!mapp(fam = me->query("family")) || (string)me->query("family/family_name") != "古墓派") 
		return notify_fail("你不是古墓派子弟，领悟不到石壁中所刻武功的奥妙。\n");

	if ( (int)me->query_skill("literate", 1) < 1)
		return notify_fail("你是个文盲，先学点文化(literate)吧。\n");

	if ( (int)me->query_skill("yunu-jue", 1) < 60)
		return notify_fail("你的玉女二十四诀火候不够，无法静下心来学习石壁上的武功。\n");

	if ( !me->query("family/master_name")) 
		return notify_fail("你没有师傅的指点，领悟不了石壁上所刻的高深武功。\n");

	if ( me->query("jing") < 80)
		return notify_fail("你的精力不够！\n");

	me->receive_damage("jing", random(80), "心力绞瘁死了");

	message_vision("$N正专心研读石壁上的武功心得。\n", me);

	switch( random(3) ) 
	{
	    case 0:
		if ( (int)me->query_skill("yunu-xinjing", 1) < 150)
		{
			me->improve_skill("yunu-xinjing", me->query_int());
			write("你对着石壁琢磨了一回儿，似乎对玉女心经有点心得。\n");
			me->set_temp("shibi2_learned",1);
		}
	    case 1:
		if ( (int)me->query_skill("yunu-jianfa", 1) < 120)
		{
			me->improve_skill("yunu-jianfa", me->query_int());
			write("你对着石壁琢磨了一回儿，似乎对玉女剑法有点心得。\n");
			me->set_temp("shibi2_learned",1);
		}
	    case 2:
		if ( (int)me->query_skill("yunu-jue", 1) < 100)
		{
			me->improve_skill("yunu-jue", me->query("int"));
			write("你对着石壁琢磨了一回儿，似乎对玉女二十四诀有点心得。\n");
			me->set_temp("shibi2_learned",1);
		}
	    case 3:
		if ( (int)me->query_skill("whip", 1) < 100)
		{
			me->improve_skill("whip", me->query_int());
			write("你对着石壁琢磨了一回儿，似乎对基本鞭法有点心得。\n");
			me->set_temp("shibi2_learned",1);
		}
	    case 4:
		if ( (int)me->query_skill("sword", 1) < 100)
		{
			me->improve_skill("parry", me->query_int());
			write("你对着石壁琢磨了一回儿，似乎对基本剑法有点心得。\n");
			me->set_temp("shibi2_learned",1);
		}
	}

	if ( !me->query_temp("shibi2_learned") )
	{
		write("你对着石壁琢磨了一回儿，发现上面所说的太过浅显，对你来说已毫无意义了。\n");
	}
	return 1;
}
