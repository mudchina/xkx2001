//Cracked by Roath
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(MAG"过桥黑鱼"NOR, ({"guoqiao heiyu", "fish"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是云南的名菜过桥黑鱼。\n");
                set("unit", "盘");
                set("value", 200);
                set("food_remaining", 4);
                set("food_supply", 80);
        }
}

