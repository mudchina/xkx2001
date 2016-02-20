//Cracked by Roath

#include <ansi.h>
inherit PILL;

void setup()
{}

int cure_ob(string);
void create()
{
	set_name(HIC"玉真散"NOR, ({"yuzhen san", "san"}));
	set_weight(80);
	if (clonep())
    	set_default_object(__FILE__);
    else 
    {
		set("unit", "包");
        set("long", "玉真散是华山派的疗伤灵药，可解紫霞功所造成的伤。\n");
		set("value", 8000);
		set("medicine", 1);
    }
        setup();
}

int cure_ob(object me)
{
	if (me->query_condition("cool_drug") > 0)
	{
	        me->add("qi", -300);
        message_vision(BLU"$N服下一包玉真散，觉得胸口闷恶难当，如中重锤。原来服食太急太多，药效适得其反！\n" NOR, me);
        destruct(this_object());
        return 1;
	}
	
   
	message_vision(HIY"$N服下一包玉真散，只觉四体通泰，伤势大大好转。\n"NOR, me);

	me->receive_curing("qi",500);	    
	me->apply_condition("cool_drug", 15);

        if ((((int)me->query_condition("hyz_damage")) > 0) && 
(((int)me->query_condition("hyz_damage")) < 30))
        	me->clear_condition("hyz_damage");
	else
  		
me->apply_condition("hyz_damage",(int)me->query_condition("hyz_damage")-30);
	destruct(this_object());
   return 1;
}

