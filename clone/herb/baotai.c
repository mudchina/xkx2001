//Cracked by Roath
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
        set_name(MAG"豹胎"NOR, ({"bao tai","baotai","tai"}));
	set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("unit", "只");
                set("long","豹胎：大补之物，疗内伤有奇效；以豹胎所炼之药，多有强筋健骨的效果。\n");
                set("value", 12000);
				set("yaocai", 1);
        		set("cure_s",30);
		        set("cure_d",0);
		        set("cure_n",72);
		
        }
        setup();
}
