//Cracked by Roath
// letter1.c 大封套

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("大封套", ({"feng tao", "tao", "envelope"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long",
			"封皮上写着八个字：“得我盒者，开启此柬”。\n");
                set("material", "paper");
        }
}

void init()
{
	add_action("do_open", "open");
}

int do_open(string arg)
{
	object ob1, ob2, me=this_player();

	if ( !arg || arg =="" )
		return notify_fail("你要将什么打开？\n");

        if ( (arg == "feng tao" || arg == "tao" || arg == "envelope" )
        && objectp(present(arg, me)) ) {
	   	if ( this_object()->query_temp("opened") )
			return notify_fail("你已经拆开信封，抽出信纸和两个小封套了！\n");

		message_vision("$N拆开信封，抽出一张残旧的信纸和两个小封套。\n", me);
		this_object()->set_name("信纸", ({"letter"}));
		this_object()->set("unit", "张");
		this_object()->set("long", HIY
		"盒中之物，留赠有缘。惟得盒者，务须先葬(bury)我骸骨，\n"
		"方可启盒，要紧要紧。\n" NOR);
		this_object()->set_temp("opened", 1);
		me->set_temp("read1", 1);

		ob1=new(__DIR__"letter3");
		ob2=new(__DIR__"letter2");
		ob1->move(me);
		ob2->move(me);

		return 1;
	}
	else return 0;
}
