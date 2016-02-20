//Cracked by Roath
inherit ITEM;
inherit F_FOOD;

void create()
{
    set_name("凉面", ({"liang mian", "mian"}));
    set_weight(100);
    if (clonep())
	set_default_object(__FILE__);
    else {
	set("long", "一碗凉面，上面撒了些芝麻，挺诱人的。\n");
	set("unit", "碗");
	set("food_remaining", 3);
	set("food_supply", 80);
	set("value", 150);
    }
}
