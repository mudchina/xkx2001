//Cracked by Roath
// candy.c Ï²ÌÇ
// Shan: 96/08/14

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("Ï²ÌÇ", ({"candy", "xi tang", "tang"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
		set("long", "Ò»¿Å°ü×ÅºìÖ½µÄÏ²ÌÇ¡£\n");
                set("unit", "¿Å");
                set("value", 2);
                set("food_remaining", 2);
                set("food_supply", 1);
        }
}

