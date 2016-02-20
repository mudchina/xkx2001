//Cracked by Roath
// mianbing.c 面饼

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("面饼", ({"mian bing", "bing"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一块香喷喷的烤面饼。\n");
		set("unit", "块");
		set("value", 60);
		set("food_remaining", 3);
		set("food_supply", 40);
	}
}
