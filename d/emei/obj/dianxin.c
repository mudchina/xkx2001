//Cracked by Roath
// dianxin.c 点心
// Shan 96/06/29

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("点心", ({"dian xin", "dianxin", "dimsum"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一碟制作精美的小点心。\n");
		set("unit", "碟");
		set("value", 100);
		set("food_remaining", 4);
		set("food_supply", 30);
	}
}
