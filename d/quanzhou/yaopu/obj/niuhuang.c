//Cracked by Roath
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
        set_name(HIY"牛黄"NOR, ({"niuhuang"}));
	set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("unit", "钱");
                set("long","牛黄：牛的胆结石，可以解毒。\n");
                set("value", 5000);
				set("yaocai", 1);
        		set("cure_s",0);
		        set("cure_d",30);
		        set("cure_n",0);
		
        }
        setup();
}
