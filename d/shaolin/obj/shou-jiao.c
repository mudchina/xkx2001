//Cracked by Roath
// shou-jiao.c

inherit ITEM;

void create()
{
	set_name("兽角", ({"shou jiao", "jiao", "unicorn"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这就是碧水金睛兽的兽角，相传用其制成的水珠功能水，且寒毒不侵。\n");
		set("unit", "支");
		set("material", "leather");
	}
	setup();
}

