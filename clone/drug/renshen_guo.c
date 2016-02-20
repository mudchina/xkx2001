//Cracked by Roath
// renshen-guo.c 人参果

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG "人参果" NOR, ({"renshen guo", "guo"}));
	set_weight(90);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "枚");
		set("long", "这是一枚人参果，看上去就像一个白白胖胖的小娃娃。\n");
		set("value", 20000);
		set("medicine", 1);
	}

	setup();
}

int cure_ob(object me)
{
	if (me->query_condition("cool_drug") > 0){
	me->add("max_neili", -1);
        message_vision(HIR "$N吃下一枚人参果，只觉得头重脚轻，摇摇欲倒，
原来服食太急太多，药效适得其反！\n" NOR, me);
        destruct(this_object());
        return 1;
        }
	me->set("eff_jing", (int)me->query("max_jing"));
	me->set("jing", (int)me->query("max_jing"));
	me->set("jingli", (int)me->query("max_jingli"));
	me->set("eff_qi", (int)me->query("max_qi"));
	me->set("qi", (int)me->query("max_qi"));
	if (random(2)==1) me->add("max_neili", 2);
	me->set("neili", (int)me->query("max_neili"));
	me->set("food", (int)me->max_food_capacity());
        me->set("water", (int)me->max_water_capacity());
        
	message_vision(HIG "$N吃下一枚人参果，只觉得精神健旺，气血充盈，体内真力源源滋生，将疲乏饥渴一扫而空! \n" NOR, me);
	me->apply_condition("cool_drug", 30);
	destruct(this_object());
	return 1;
}
