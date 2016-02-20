//Cracked by Roath
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
        set_name(HIG"荷叶"NOR, ({"he ye","heye","ye"}));
	set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("unit", "张");
                set("long","荷叶：普通荷花叶，可清热去火。\n");
                set("value", 50);
				set("yaocai", 1);
        		set("cure_s",0);
		        set("cure_d",3);
		        set("cure_n",0);
		
        }
        setup();
}
