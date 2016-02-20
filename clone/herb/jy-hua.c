//Cracked by Roath
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
        set_name(HIY"金"HIW"银"HIC"花"NOR, ({"jinyin hua","hua"}));
	set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("unit", "钱");
                set("long","金银花：藤本植物，花分金银二色，可入药，败火剂。\n");
                set("value", 30);
				set("yaocai", 1);
        		set("cure_s",0);
		        set("cure_d",1);
		        set("cure_n",0);
		
        }
        setup();
}
