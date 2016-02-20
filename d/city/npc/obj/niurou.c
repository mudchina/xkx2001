//Cracked by Roath
// niurou.c  Ï≈£»‚

inherit ITEM;
inherit F_FOOD;

void init();
int do_cut(string);

void create()
{
        set_name(" Ï≈£»‚", ({"shou niurou", "rou"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "“ªÎ∫œ„≈Á≈Áµƒ Ï≈£»‚°£\n");
                set("unit", "Î∫");
                set("value", 120);
                set("food_remaining", 3);
                set("food_supply", 80);
        }
        setup();
}
