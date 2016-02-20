//Cracked by Roath
// zhenggao.c 蒸糕

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("蒸糕", ({"zheng gao", "cake"}));
        set_weight(40);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一碟冒着热气的蒸糕。\n");
                set("unit", "碟");
                set("value", 10);
                set("food_remaining", 3);
                set("food_supply", 15);
        }
}
