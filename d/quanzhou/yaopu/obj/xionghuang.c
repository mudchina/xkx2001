//Cracked by Roath
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
        set_name(HIY"ÐÛ»Æ"NOR, ({"xionghuang"}));
	set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("unit", "Ç®");
                set("long","ÐÛ»Æ¡£\n");
                set("value", 100);
				set("yaocai", 1);
        		set("cure_s",0);
		        set("cure_d",20);
		        set("cure_n",0);
		
        }
        setup();
}
