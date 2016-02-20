//Cracked by Roath
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
        set_name(HIR"藏红花"NOR, ({"zanghonghua","hua"}));
	set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("unit", "钱");
                set("long","藏红花：补血之物，但过量则败血。\n");
                set("value", 2000);
				set("yaocai", 1);
        		set("cure_s",30);
		        set("cure_d",0);
		        set("cure_n",0);
		
        }
        setup();
}
