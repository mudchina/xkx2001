//Cracked by Roath
// jiuyin_force_book.c 九阴真经内功篇
// by sdong 08/98

inherit ITEM;
inherit F_UNIQUE;
#include <ansi.h>

int do_read(string arg);

void create()
{
		  set_name(HIB"九阴真经"NOR, ({ "jiuying zhenjing", "zhenjing" }));
		  set_weight(600);
		  if( clonep() )
					 set_default_object(__FILE__);
		  else {
					 set("unit", "本");
					 set("long", "这是一本残破的线装书，上书《九阴真经上篇之内功心法》，里面记载了上乘的内功心法，可惜缺了好多页。\n");
					 set("value", 1000000);
					 set("material", "paper");
					 set("skill", ([
								"name": "force",        // name of the skill
								"exp_required": 1000000,  // minimum combat experience required
								"jing_cost":    100,     // jing cost every time study this
								"difficulty":   30,     // the base int to learn this skill
								"max_skill":    500      // the maximum level you can learn
					 ]) );
		  }
		  ::create();
}

void init()
{
		  add_action("do_read", "du");
		  add_action("do_read", "study");
}

int do_read(string arg)
{
	object me = this_player();

		if( me->query("9yin") != "granted" )
		{
			message_vision("$N搅尽脑汁也看不明白这本$n。\n",me,this_object());
			return 1;
		}
		else return "/cmds/skill/du.c"->main(me, arg);

}


