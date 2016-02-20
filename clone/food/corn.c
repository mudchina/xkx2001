//Cracked by Roath
#include <ansi.h> 
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(BBLK+YEL "烤玉米" NOR, ({"corn", "kao yumi", "yumi"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一个看起来很诱人的玉米，热腾腾的不断散发出香味。\n"  );
                set("unit", "个");
                set("value", 50);
                set("food_remaining", 5);
                set("food_supply", 20);
        }
}

