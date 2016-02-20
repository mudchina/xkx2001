//Cracked by Roath
// candou.c ²Ï¶¹

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("²Ï¶¹", ({"can dou", "dou"}));
        set_weight(60);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "Ò»µúÏãÅçÅçµÄ²Ï¶¹¡£\n");
                set("unit", "µú");
                set("value", 15);
                set("food_remaining", 1);
                set("food_supply", 30);
        }
}
