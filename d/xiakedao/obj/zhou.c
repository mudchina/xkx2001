//Cracked by Roath
// zhou.c 腊八粥
// updated by sdong 6/1999
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIG "腊八粥" NOR, ({"laba zhou", "zhou"}));
        set_weight(90);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "碗");
                set("value", 20000);
                set("food_supply", 30);
        }

        setup();
}
void init()
{
	add_action("do_eat", "eat");
}
int do_eat(string arg)
{	object it = this_object(), me = this_player();
	
	if( !it->id(arg) ) return 0;
	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成。\n");
	if( (int)me->query("food") 
			>= (int)me->max_food_capacity() )
		return notify_fail("你已经吃饱了。\n");
	me->add("food", (int)query("food_supply"));

	if( base_name(environment(me)) != "/d/xiakedao/dadong" )
	{
		message_vision(HIY "$N喝下一碗腊八粥。\n", me);
		write("粥冷了，药味又浓，真难喝。\n");
		destruct(it);
		return 1;
	}

	me->set("eff_jing", (int)me->query("max_jing"));
	me->set("jing", (int)me->query("max_jing"));
	me->set("jingli", (int)me->query("max_jingli"));
	me->set("eff_qi", (int)me->query("max_qi"));
	me->set("qi", (int)me->query("max_qi"));
	me->set("neili", (int)me->query("max_neili"));
	if (random(2)==1) me->add("max_neili", 2);

	message_vision(HIG "$N喝下一碗腊八粥。\n", me);
	write("虽然药气刺鼻，但并不难喝。一碗粥下肚，将疲乏一扫而空。\n");
	destruct(it);
	return 1;
}
