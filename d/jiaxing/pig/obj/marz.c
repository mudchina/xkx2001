//Cracked by Roath
// Jay 5/23/96

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("火星人", ({"marz"}));
        set_weight(70);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "火星人可以作为地球人的食品。\n");
                set("unit", "只");
                set("food_remaining", 19);
                set("food_supply",1 );
        }
}

