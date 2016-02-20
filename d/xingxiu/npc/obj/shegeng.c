//Cracked by Roath
// Jay 10/8/96

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("蛇羹", ({"shegeng", "geng"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一碗香喷喷的蛇羹，营养好极了。\n");
                set("unit", "碗");
                set("value", 75);
                set("food_remaining", 4);
                set("food_supply", 60);
        }
}

