//Cracked by Roath
// tangbao.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("汤包", ({"tang bao", "bao"}));
        set_weight(70);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "汤包是泉州的特产。\n");
                set("unit", "碗");
                set("value", 45);
                set("food_remaining", 3);
                set("food_supply", 30);
        }
}

