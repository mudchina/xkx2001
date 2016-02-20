//Cracked by Roath
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
        set_name(YEL"蝉蜕"NOR, ({"chantui"}));
	set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("unit", "钱");
                set("long","蝉蜕：蝉由幼虫蜕变至成虫所遗的壳，有去风湿的效果。\n");
                set("value", 80);
				set("yaocai", 1);
        		set("cure_s",3);
		        set("cure_d",0);
		        set("cure_n",0);
		
        }
        setup();
}
