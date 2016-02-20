//Cracked by Roath
#include <ansi.h> 
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(BRED+WHT "水晶肴肉" NOR, ({"shuijing yaorou", "yaorou", "rou"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一盘肉色鲜红，皮白光滑晶莹．卤冻透明，状如水晶，肉质清香而醇酥，\n油润不腻，味道鲜美的水晶肴肉。\n"  );
                set("unit", "盘");
                set("value", 250);
                set("food_remaining", 5);
                set("food_supply", 50);
        }
}

