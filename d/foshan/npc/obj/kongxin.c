//Cracked by Roath
// Jay 5/23/96

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("©упд╡к", ({"kongxin cai", "cai"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "р╩©цблсмсм╣д©упд╡к║ё\n");
                set("unit", "©ц");
                set("food_remaining", 3);
                set("food_supply",20 );
        }
}

