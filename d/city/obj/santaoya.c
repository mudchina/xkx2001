//Cracked by Roath
#include <ansi.h> 
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(YEL "三套鸭" NOR, ({"santao ya", "ya"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "用湖鸭、野鸭、菜鸽三禽相配，用宜兴产的紫沙锅，文火宽汤炖焖\n而成，家鸭肥美，野鸭香酥，菜鸽鲜嫩，风味独特，滋味极佳，是扬\n州各种鸭菜中最著名的一种。  
\n"  );
                set("unit", "盆");
                set("value", 510);
                set("food_remaining", 3);
                set("food_supply", 60);
        }
}
