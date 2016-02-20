//Cracked by Roath
//À°Èâ

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("À°Èâ", ({"la rou","rou"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "Ò»´ó¿éÏãÅçÅçµÄËÄ´¨À°Èâ\n");
                set("unit", "¿é");
                set("value", 100);
                set("food_remaining", 7);
                set("food_supply", 50);
        }
}
