//Cracked by Roath
// Jay 5/3/97

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("烧饼", ({"shaobing", "cake"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一张香喷喷的大烧饼，里面有葱花，外面有芝麻。\n");
                set("unit", "张");
                set("value", 70);
                set("food_remaining", 3);
                set("food_supply", 30);
        }
}

