//Cracked by Roath
//sanhuang-wan.c
//kane 1998.6
// xQin 04/01

#include <ansi.h>
inherit PILL;

void setup()
{}

int cure_ob(string);
void create()
{
	set_name(HIY"三黄宝蜡丸"NOR, ({"sanhuang wan","wan"}));
	set_weight(50);
	if (clonep())
    	set_default_object(__FILE__);
    else
    {
	set("unit", "颗");
	set("no_sell",1);
        set("no_get",1);
        set("no_drop",1);
        set("long",
"一颗黄澄澄的药丸，由牛黄、雄黄、雌黄这三黄为主，辅以其它药物\n炼制而成，是武当派疗伤、疗毒的灵药。对虫毒有奇效。\n");
		set("value", 20000);
		set("medicine", 1);
    }
        setup();
}

int cure_ob(object me)
{
	if (me->query_condition("hot_drug") > 0)
	{
       	if (me->query("neili") > 500)
	       	me->add("neili", -500);
		else
			me->add("neili",-(me->query("neili")));

		message_vision(BLU"$N服下一颗"+query("name")+BLU"，觉得体内真气逆行，内力大损。原来服食\n太急太多，药效适得其反！\n" NOR, me);
        destruct(this_object());
        return 1;
	}
   	
	message_vision(HIM"$N服下一颗"+query("name")+HIM"，只觉通体舒泰，精神焕发，伤势大有好转。\n"NOR, me);
	me->receive_heal("qi", 400+random(200));
	me->apply_condition("hot_drug", 15);

	if ((int)me->query_condition("insect_poison") )
	{
	me->apply_condition("insect_poison", 0);
	}
        destruct(this_object());
   	return 1;
}


