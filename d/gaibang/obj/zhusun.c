//Cracked by Roath
// zhusun 竹笋

inherit ITEM;

void create()
{
	set_name("竹笋", ({"zhu sun", "bamboo shoot", "shoot"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一把新鲜嫩绿的竹笋。\n");
		set("unit", "把");
		set("value", 0);
	}
}
