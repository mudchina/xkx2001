//Cracked by Roath
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
        set_name(HIY"川贝"NOR, ({"chuanbei"}));
	set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("unit", "钱");
                set("long","川贝：多年生草本植物，可提气润肺，益补三焦，对内外伤都有疗效。\n");
                set("value", 400);
				set("yaocai", 1);
        		set("cure_s",10);
		        set("cure_d",0);
		        set("cure_n",0);
		
        }
        setup();
}
