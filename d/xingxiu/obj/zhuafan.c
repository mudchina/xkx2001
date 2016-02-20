//Cracked by Roath
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("抓饭", ({"zhua fan", "fan"}));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一盘香喷喷的抓饭，是大米、羊肉、胡萝卜等混和清油焖制，吃的时侯要净手捏团抓食。\n");
		set("unit", "盘");
		set("value", 100);
		set("eat_msg", "$N伸手在盘里抓起一团抓饭送入嘴里。\n");
		set("food_remaining", 4);
		set("food_supply", 40);
	}
}
