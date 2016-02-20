//Cracked by Roath
inherit ITEM;
inherit F_FOOD;

void create()
{
    set_name("冰糖葫芦", ({"hulu"}));
    set_weight(50);
    if (clonep())
	set_default_object(__FILE__);
    else {
	set("long", "红红的山楂，亮晶晶的冰糖，你的口水快出来了。\n");
	set("unit", "串");
	set("food_remaining", 5);
	set("value", 150);
    }
}
