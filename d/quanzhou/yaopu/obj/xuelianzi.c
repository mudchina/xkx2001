//Cracked by Roath
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
        set_name(HIW"雪莲子"NOR, ({"xuelian zi"}));
	set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("unit", "包");
                set("long","雪莲子，白色，无味，补血理气，清毒化瘀。\n");
                set("value", 7000);
				set("yaocai", 1);
        		set("cure_s",20);
		        set("cure_d",30);
		        set("cure_n",40);
		
        }
        setup();
}
