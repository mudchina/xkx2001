//Cracked by Roath
//huiyang-san.c 回阳五龙散
//kane 1998.6
#include <ansi.h>
inherit PILL;

void setup()
{}

int cure_ob(string);
void create()
{
	set_name(HIY"回阳五龙散"NOR, ({"huiyang san","san"}));
	set_weight(50);
	if (clonep())
    	set_default_object(__FILE__);
    else
    {
		set("unit", "包");
        set("long", 
"崆峒派常用的疗伤灵药。粉末微细，色泽淡黄，微有辛辣刺鼻的味道\n
，对水冲服效果尤佳。\n");
		set("value", 10000);
		set("medicine", 1);
    }
        setup();
}

int cure_ob(object me)
{
	if (me->query_condition("hot_drug") > 0)
	{
	        if (me->query("jingli") > 500)
		        me->add("jingli", -500);
		else
			me->add("jingli",-(me->query("jingli")));

		message_vision(BLU"$N服下一包"+query("name")+BLU"，觉得胸口郁闷，四肢乏力。原来服食太急\n太多，药效适得其反！\n" NOR, me);
        	destruct(this_object());
        	return 1;
	}
   	
	message_vision(HIY"$N服下一包"+query("name")+HIY"，只觉通体舒泰，精神焕发，伤势大有好转。\n"NOR, me);
	me->receive_heal("qi", 100+random(200));
	me->add("jingli",100+random(200));
	me->apply_condition("hot_drug", 30);

	if ((int)me->query_condition("snake_poison") > 0) 	
    		me->apply_condition("snake_poison",0);
  	destruct(this_object());
   	return 1;
}

void init()
{
        add_action("do_pour", "pour");
}

int effect_in_liquid(object ob)
{

	tell_object(this_player(),HIG"你只觉得体内一股暖气流动，大为受用。\n"NOR);
	this_player()->receive_heal("qi",10+random(20));
       return 0;
}


