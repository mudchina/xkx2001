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
	else {
		this_player()->receive_curing("qi", 50);
		message_vision("$N小心翼翼地把一包金创药敷在伤口上，只觉伤势大为好转，气色看起来好多了。\n", this_player());
		add_amount(-1);
		return 1;
	}
}

