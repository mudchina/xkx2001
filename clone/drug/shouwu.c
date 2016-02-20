//Cracked by Roath
// shouwu.c 何首乌

inherit ITEM;
#include <ansi.h>

void setup()
{}
int cure_ob(string);
void create()
{
	set_name("何首乌", ({"heshou wu", "wu"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "棵");
		set("long", "这是一棵初具人形的何首乌。\n");
		set("value", 10000);
		set("medicine", 1);
	}
	setup();
}

int cure_ob(object me)
{
	if ( (int)me->query_condition("bonze_drug" ) > 0 )
        {
                me->add("max_neili", -1);
		me->apply_condition("bonze_drug", 30);
                message_vision(HIR "$N吃下一支何首乌，只觉得头重脚轻，火气翻腾，原来服食太多，药效适得其反！\n" NOR, me);
		destruct(this_object());
        }
	if( random(2) == 1)
	{
        message_vision("$N吃下一棵何首乌，嘴里觉得甜甜的。\n", me);
        destruct(this_object());
        return 1;
        }
	else
	{
	me->add("max_neili", 1);
	message_vision(HIG"$N吃下一棵何首乌，顿时间觉得全身充满了活力 !\n"NOR, me);
	}
	me->apply_condition("bonze_drug", 
	this_player()->query_condition("bonze_drug")+30);
	destruct(this_object());
	return 1;
}

