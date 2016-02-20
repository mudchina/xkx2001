//Cracked by Roath
//fixed by sage 5/08/2001
// guo1.c 野果
// ssy
#include <ansi.h>

inherit ITEM;

int do_eat(string);

void create()
{
        set_name(RED "野果" NOR, ({"ye guo", "guo"}));
        set_weight(90);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "枚");
                set("long", "这是一枚红艳艳的野果。\n");
                set("value", 20000);
        }
        setup();
}

void init()
{
	set("no_get","这东西不能随便拿! \n");
	set("no_drop","这么宝贵的野果，哪能乱扔! \n");
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{	object it = this_object(), me = this_player();
	
	if( !arg )
                return notify_fail("吃什么？\n");
        if ( arg != "guo" )
                return notify_fail("什麽？\n");

	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成。\n");
	if( (int)me->query("food") 
	    >= (int)me->max_food_capacity() )
	  {
	    message("vision","你已经吃饱了。\n", me);
	    return 1;
	  }
	  if ((int)me->query("combat_exp") > 250)

        return notify_fail("侠客岛的东西是不能随便吃的。\n");

	me->add("food", 50);
        me->add("water", 50);

	me->set("jing", (int)me->query("max_jing"));
        me->set("jingli", (int)me->query("max_jingli"));


	message_vision(RED "$N吃下一枚野果，顿时觉得精神旺盛，浑身上下充满了精力。\n" NOR, me);
	destruct(it);
	return 1;
}
