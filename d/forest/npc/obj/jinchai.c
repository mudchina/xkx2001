//Cracked by Roath
inherit ITEM;

void create()
{
	set_name("金钗", ({ "jin chai", "chai" }));
	set("weight", 400);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","钗上一颗明珠又大又圆，宝光莹然，是一件希世之珍。\n");
		set("unit", "支");
		set("value", 3000);
		set("material", "gold");
		set("armor_prop/armor", 1);
	}
	setup();
}	
