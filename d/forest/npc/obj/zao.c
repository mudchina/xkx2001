//Cracked by Roath
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("‘Ê", ({"zao"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "“ª¡£≥… Ïµƒ∫Ï‘Ê°£\n");
                set("unit", "¡£");
                set("food_remaining", 1);
                set("food_supply",20 );
        }
}

