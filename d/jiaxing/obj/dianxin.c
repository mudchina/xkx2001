//Cracked by Roath
// dianxin.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("点心", ({"dian xin", "dianxin"}));
        set_weight(70);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "点心是泉州的特产，款式众多，美味可口。\n");
                set("unit", "碟");
                set("value", 60);
                set("food_remaining", 3);
                set("food_supply", 40);
        }
}

