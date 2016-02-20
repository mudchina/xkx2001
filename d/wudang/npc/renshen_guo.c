//Cracked by Roath
// renshen-guo.c 人参果

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
	                                      
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIG "人参果" NOR, ({"renshen guo", "guo"}));
	set_weight(90);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "枚");
		set("long", "这是一枚人参果，看上去就像一个白白胖胖的小娃娃。\n");
		set("no_drop","这么宝贵的人参果，哪能乱扔！ \n");
		set("value", 10000);
	}

	setup();
}

int do_eat(string arg)
{
	object me = this_player();

	if (!id(arg))
		return notify_fail("你要吃什么？\n");

	me->set("eff_jing", (int)me->query("max_jing"));
	me->set("jing", (int)me->query("max_jing"));
	me->set("eff_qi", (int)me->query("max_qi"));
	me->set("qi", (int)me->query("max_qi"));
	me->set("neili", (int)me->query("max_neili"));
	me->set("max_neili", (int)me->query("max_neili")+1);
	me->set("food", (int)me->max_food_capacity());
        me->set("water", (int)me->max_water_capacity());
        
	message_vision(HIG "$N吃下一枚人参果，只觉得精神健旺，气血充盈，体内真力源源滋生，将疲乏饥渴一扫而空! \n" NOR, me);

	destruct(this_object());
	return 1;
}
