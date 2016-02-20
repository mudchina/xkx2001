//Cracked by Roath
// box1.c 大铁盒

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("铁盒", ({"tie he", "he", "box"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("long",
			"此盒高约一尺，两尺见方，却轻飘飘地似乎没藏着什么东西。\n");
                set("material", "steel");
		set("value", 100);
        }
}

void init()
{
	add_action("do_open", "open");
	add_action("do_pull", "pull");
}

int do_open(string arg)
{
	object ob1, ob2, me=this_player();

	if ( !arg || arg =="" )
		return notify_fail("你要将什么打开？\n");

        if ( (arg == "tie he" || arg == "he" || arg == "box" )
        && objectp(ob1 = present(arg, me)) ) {
	   	if ( !ob1->query_temp("opened") ) {	
			message_vision("$N打开大铁盒，发现一盒中有个大信封。\n", me);

		tell_object(me, "你发现盒子浅得出奇，离底仅有一寸，料得必有夹层。\n");
		ob1->set_temp("opened", 1);
		message_vision("$N将大信封拿起来。\n", me);

		ob2=new(__DIR__"letter1");
		ob2->move(me);
	   }
	   else {
		message_vision("$N打开大铁盒。\n", me);
		tell_object(me, "你发现盒子浅得出奇，离底仅有一寸，料得必有夹层。\n");
	   }

	   return 1;
	}
	else return 0;
}

int do_pull(string arg)
{
	object ob, ob1, me=this_player();

	if ( !arg || arg =="" )
                return 0;

	if ( ob = present(arg, me) ) {
		message_vision("$N按下铁盒左右机括，双手捧盒力掀，只听得“呀”的一声，铁盒即开。\n", me);
		message_vision(HIR"突然只听得“嗤嗤”阵响，数十枚短箭由铁盒内射出，将$N射成了刺猬！\n"NOR, me);

                ob1=new(__DIR__"jinshe_book1");
                ob1->move(environment(me));

		me->receive_wound("qi", me->query("max_qi")+100, "被毒箭射死了");

		destruct(ob);
	
		return 1;
	}

	return 0;
}
