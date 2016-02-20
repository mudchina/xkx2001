//Cracked by Roath
// Jay 5/3/97

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("油条", ({"youtiao"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一根油光光的油条，炸得酥松可口。\n");
                set("unit", "根");
                set("value", 60);
                set("food_remaining", 2);
                set("food_supply", 40);
        }
}

