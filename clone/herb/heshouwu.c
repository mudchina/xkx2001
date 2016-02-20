//Cracked by Roath
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
        set_name(HIY"何首乌"NOR, ({"heshouwu","shouwu"}));
	set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("unit", "支");
                set("long","何首乌：草本植物，块根可入药，百年以上之物渐具人形，乃滋补佳品。\n");
                set("value", 6000);
				set("yaocai", 1);
        		set("cure_s",80);
		        set("cure_d",0);
		        set("cure_n",10);
		
        }
        setup();
}
