//Cracked by Roath
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
        set_name(YEL"防风"NOR, ({"fangfeng"}));
	set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("unit", "钱");
                set("long","防风：常见中药，用以调理肝脏。\n");
                set("value", 200);
				set("yaocai", 1);
        		set("cure_s",0);
		        set("cure_d",0);
		        set("cure_n",5);
		
        }
        setup();
}
