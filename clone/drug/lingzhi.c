//Cracked by Roath
//lingzhi.c

#include <ansi.h>

inherit ITEM;

int cure_ob(string);
void init();

void create()
{
	set_name(HIG "灵芝" NOR, ({"ling zhi", "zhi"}));
	set_weight(20);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "枚");
		set("long", "：这是一枚灵芝，长约四寸，如伞状，通体晶白。\n");
		set("value", 20000);
		set("medicine", 1);
	}

	setup();
}

int cure_ob(object me)
{
	if (me->query_condition("cool_drug") > 0){
        me->add("max_jingli", -1);
        me->add("eff_jingli", -1);
        message_vision(HIR "$N吃下一枚灵芝，只觉得头重脚轻，摇摇欲倒，原来服食太急太多，药效适得其反！\n" NOR, me);
        destruct(this_object());
        return 1;
        }
	me->set("eff_jing", (int)me->query("max_jing"));
	me->set("jing", (int)me->query("max_jing"));
	me->set("eff_qi", (int)me->query("max_qi"));
	me->set("jingli", (int)me->query("max_jingli"));
	me->set("qi", (int)me->query("max_qi"));
	me->set("neili", (int)me->query("max_neili"));
        
	message_vision(HIG "$N吃下一枚灵芝，只觉得精神健旺，气血充盈，体内真力源源滋生，甚至不再感到饥饿干渴! \n" NOR, me);

	me->apply_condition("cool_drug", 30);
	destruct(this_object());
	return 1;
}
