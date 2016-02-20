//Cracked by Roath
//heishi-dan.c
//kane 1998.5
#include <ansi.h>
inherit PILL;

void setup()
{}

int cure_ob(string);
void create()
{
	set_name(BLU"玉洞黑石丹"NOR, ({"yudong dan", "heishi dan", "dan"}));
	set_weight(50);
	if (clonep())
    	set_default_object(__FILE__);
    else 
    {
		set("unit", "颗");
        set("long", "黑黑的一颗药丸，毫不起眼，却是崆峒派的疗伤圣药。\n");
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
        	{
	        	me->add("neili", -500);
	        }
			else
			{
				me->add("neili",-(me->query("neili")));
			}	
        	message_vision(BLU"$N服下一颗黑石玉洞丹，觉得体内真气翻涌，内力大损。原来服食太急太多，药效适得其反！\n" NOR, me);
        	destruct(this_object());
        	return 1;
	}
	message_vision(BLU"$N服下一颗黑石玉洞丹，只觉三焦通畅，五气调和，内外伤都大有好转。\n"NOR, me);
        me->set("eff_qi", (int)me->query("max_qi"));
        me->set("qi", (int)me->query("max_qi"));
		me->apply_condition("hot_drug", 20);

        if ((((int)me->query_condition("qs_damage")) > 0) && (((int)me->query_condition("qs_damage")) < 30))
        	me->apply_condition("qs_damage",0);
  		else
	  		me->apply_condition("qs_damage",(int)me->query_condition("qs_damage")-30);
		destruct(this_object());
	    return 1;
}

