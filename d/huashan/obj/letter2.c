//Cracked by Roath
// letter2.c 小封套

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("小封套", ({"feng tao", "tao", "envelope"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long",
			"封皮上写着：“启盒之法”。\n");
                set("material", "paper");
        }
}

void init()
{
	add_action("do_open", "open");
}

int do_open(string arg)
{
	object me=this_player();

	if ( !arg || arg =="" )
		return notify_fail("你要将什么打开？\n");

        if ( (arg == "feng tao" || arg == "tao" || arg == "envelope" )
        && objectp(present(arg, me)) ) {	
		if ( this_object()->query_temp("opened") )
			return notify_fail("你已经拆开信封，抽出信纸了！\n");

		message_vision("$N拆开信封，抽出一张残旧的信纸。\n", me);
		this_object()->set_name("信纸", ({"letter"}));
		this_object()->set("unit", "张");
		this_object()->set("long", HIG
		"铁盒左右，各有机括，双手捧盒力掀(pull)，铁盒即开。\n" NOR);

		this_object()->set_temp("opened", 1);
		me->set_temp("read2", 1);

		return 1;
	}
	else return 0;
}
