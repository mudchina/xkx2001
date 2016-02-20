//Cracked by Roath
// jinchuang.c 金创药

//inherit ITEM;
inherit COMBINED_ITEM;
void setup()
{}

int cure_ob(string);
void create()
{
	set_name("金创药", ({"jinchuang yao", "jin", "jinchuang"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "些");
		set("base_unit", "包");
		set("long", "这是一包武林人士必备的金创药。\n");
		set("value", 5000);
		set("medicine", 1);
	}
	::set_amount(1);
}

int cure_ob(object me)
{
	if ((int)this_player()->query("eff_qi") == 
	    (int)this_player()->query("max_qi"))
		return notify_fail("你现在不需要用金创药。\n");
	else if (this_player()->query_condition("jin_used") > 0) {
		add_amount(-1);
		message_vision("$N小心翼翼地把一包金创药敷在伤口上。\n", this_player());
		return 1;
	}
	else if ((int)this_player()->query("eff_qi") < 10
	      || (int)this_player()->query("qi") < 10) {
		add_amount(-1);
		message_vision("$N小心翼翼地把一包金创药敷在伤口上，可是鲜血涌出，将药粉都冲开了。\n", this_player());
		return 1;
	}
	else {
		this_player()->receive_curing("qi", 50+random(100));
		add_amount(-1);
		message_vision("$N小心翼翼地把一包金创药敷在伤口上，只觉伤势大为好转，气色看起来好多了。\n", this_player());
		this_player()->apply_condition("jin_used", 1+random(3));
		return 1;
	}
}

