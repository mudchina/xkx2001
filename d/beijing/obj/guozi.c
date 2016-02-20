//Cracked by Roath
inherit ITEM;
inherit F_FOOD;

void create()
{
    set_name("煎饼果子", ({"jianbing", "guozi"}));
    set_weight(100);
    if (clonep())
	set_default_object(__FILE__);
    else {
	set("long", "这是一张热乎乎的煎饼果子，上面的鸡蛋还流这黄呢。\n");
	set("unit", "张");
	set("food_remaining", 3);
	set("food_supply", 50);
	set("value", 100);
    }
}
