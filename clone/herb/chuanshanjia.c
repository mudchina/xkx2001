//Cracked by Roath
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
        set_name(YEL"穿山甲"NOR, ({"chuanshanjia"}));
	set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("unit", "钱");
                set("long","穿山甲：一种食蚁兽，皮甲坚厚，可入药，能理气调元，补养内脏，对内伤极为有效。\n");
                set("value", 2500);
				set("yaocai", 1);
        		set("cure_s",0);
		        set("cure_d",0);
		        set("cure_n",30);
		
        }
        setup();
}
