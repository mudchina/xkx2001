//Cracked by Roath
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
        set_name(HIY"黄连"NOR, ({"huanglian"}));
	set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("unit", "钱");
                set("long","黄连：草本植物，味苦，清热毒。\n");
                set("value", 4000);
				set("yaocai", 1);
        		set("cure_s",0);
		        set("cure_d",20);
		        set("cure_n",0);
		
        }
        setup();
}

void init()
{
	add_action("do_taste","taste");
}



int do_taste()
{
	object me = this_player();
/*	message_vision("very bitter\n",me);
*/	me->set("combat_exp_last",me->query("combat_exp");
}
