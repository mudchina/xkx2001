//Cracked by Roath
// turou.c Å£Èâ

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("Å£Èâ", ({"niu rou", "rou", "niu"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "Ò»µúÏãÅçÅçµÄÅ£Èâ\n");
                set("unit", "µú");
                set("value", 100);
                set("food_remaining", 4);
                set("food_supply", 50);
        }
}
