//Cracked by Roath
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
        set_name(HIG"茯苓"NOR, ({"fuling"}));
	set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("unit", "钱");
                set("long","茯苓：草本植物，补气血，润五脏，是不可多得的上佳药材。\n");
                set("value", 10000);
				set("yaocai", 1);
        		set("cure_s",40);
		        set("cure_d",0);
		        set("cure_n",53);
		
        }
        setup();
}
