//Cracked by Roath
// jianbing.c ¼å±ý

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("¼å±ý", ({"jian bing", "pancake"}));
        set_weight(40);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "Ò»µú½¹ÏãµÄ¼å±ý¡£\n");
                set("unit", "µú");
                set("value", 10);
                set("food_remaining", 3);
                set("food_supply", 15);
        }
}
