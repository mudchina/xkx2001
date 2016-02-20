//Cracked by Roath
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("烤羊腿", ({"kao yangtui", "yangtui","yang","tui"}));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一只烤得香喷喷的羊腿。\n");
		set("unit", "只");
		set("value", 100);
		set("food_remaining", 4);
		set("food_supply", 60);
	}
}
