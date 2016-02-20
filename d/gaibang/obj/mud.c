//Cracked by Roath
// ni.c 泥

inherit ITEM;

void create()
{
	set_name("湿泥", ({"shi ni", "mud"}));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一团从西湖挖来的湿泥。\n");
		set("unit", "团");
		set("value", 0);
	}

	setup();
}

