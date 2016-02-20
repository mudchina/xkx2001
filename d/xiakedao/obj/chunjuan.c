//Cracked by Roath
// chunjuan.c ´º¾í

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("´º¾í", ({"chun juan", "eggroll"}));
        set_weight(40);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "Ò»µúÕ¨µÄ½ð»ÆµÄ´º¾í¡£\n");
                set("unit", "µú");
                set("value", 10);
                set("food_remaining", 3);
                set("food_supply", 15);
        }
}
