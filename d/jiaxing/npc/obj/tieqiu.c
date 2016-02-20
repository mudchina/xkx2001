//Cracked by Roath
inherit ITEM;

void create()
{
	set_name("铁球", ({ "tie qiu", "qiu" }));
	set("weight", 1500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","虽然它和普通的铁球别无二致，可你总觉得里面有些蹊跷。\n");
		set("unit", "只");
		set("material", "iron");
	}
	setup();
}	
