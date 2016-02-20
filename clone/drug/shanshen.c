//Cracked by Roath
// shanshen.c 老山叁

inherit ITEM;
#include <ansi.h>
void setup()
{}

int cure_ob(string);
void create()
{
	set_name("老山参", ({"laoshan shen", "shen"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "株");
		set("long", "这是一株沾满山泥的长白老山参。\n");
		set("value", 10000);
		set("medicine", 1);
	}
	setup();
}

int cure_ob(object me)
{
	if ( (int)me->query_condition("bonze_drug" ) > 0 )
        {
                me->add("eff_jingli", -1);
		me->add("max_jingli", -1);
                message_vision(HIR "$N吃下一支老山参，只觉得头重脚轻，火气翻腾，原来服食太多，药效适得其反！\n" NOR, me);
		destruct(this_object());
	}
	if( random(2) == 1)
	{
	message_vision("$N吃下一株老山参，嘴里觉得甜甜的。\n", me);
	destruct(this_object());
	return 1;
	}
	else{
		me->add("eff_jingli", 1);
		me->add("max_jingli", 1);
	message_vision(HIG"$N吃下一株老山参，只觉得浑身一股热气兜底冒了上来 !\n" NOR, me);
	}
	me->apply_condition("bonze_drug", 
	this_player()->query_condition("bonze_drug")+30);
	destruct(this_object());
	return 1;
}


