//Cracked by Roath
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
        set_name(GRN"生地"NOR, ({"shengdi"}));
	set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("unit", "钱");
                set("long","生地：常见中药，疗内伤。\n");
                set("value", 1000);
				set("yaocai", 1);
        		set("cure_s",0);
		        set("cure_d",0);
		        set("cure_n",15);
		
        }
        setup();
}
