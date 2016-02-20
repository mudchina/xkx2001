//Cracked by Roath
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
        set_name(HIR"èÛè××Ó"NOR, ({"gouzhi zi","gouzhi","zi"}));
	set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("unit", "°ü");
                set("long","èÛè××Ó£¬Î¶¸Ê£¬É«ºì£¬²¹ÑªÁ¼Ò©¡£\n");
                set("value", 100);
				set("yaocai", 1);
        		set("cure_s",5);
		        set("cure_d",0);
		        set("cure_n",0);
		
        }
        setup();
}
