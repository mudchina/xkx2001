//Cracked by Roath
#include <ansi.h> 
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIY "太湖银鱼" NOR, ({"taihu yinyu", "yinyu", "fish"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "银鱼肉质细嫩，与鲚鱼、白虾并称“太湖三宝”，此品色泽金黄，肥鲜香嫩。\n"  );
                set("unit", "盘");
                set("value", 420);
                set("food_remaining", 5);
                set("food_supply", 60);
        }
}
