//Cracked by Roath
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
        set_name(HIW"巴豆"NOR, ({"ba dou","dou"}));
	set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("unit", "钱");
                set("long","巴豆：色白，形如蚕豆，磨粉后可作清泻剂，故可解毒，多用伤身，慎用。\n");
                set("value", 1000);
				set("yaocai", 1);
        		set("cure_s",-1);
		        set("cure_d",2);
		        set("cure_n",0);
		
        }
        setup();
}
