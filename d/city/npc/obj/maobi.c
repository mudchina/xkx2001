//Cracked by Roath
// Write by Wzfeng 12-29

inherit ITEM;

void create()
{
	set_name("毛笔", ({"mao bi", "bi"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一只用上好羊毛制成的毛笔，上面沾满了黑墨。\n");
		set("unit", "支");
		set("value", 100);
	}
}
