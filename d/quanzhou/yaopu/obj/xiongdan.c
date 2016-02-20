//Cracked by Roath
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
        set_name(GRN"熊胆"NOR, ({"xiong dan", "dan"}));
	set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("unit", "颗");
                set("long","熊胆，通瘀顺气，培元固本，疗内外伤之佳品。\n");
                set("value", 8000);
				set("yaocai", 1);
        		set("cure_s",30);
		        set("cure_d",0);
		        set("cure_n",45);
		
        }
        setup();
}
