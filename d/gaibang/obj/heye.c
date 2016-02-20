//Cracked by Roath
// heye 荷叶
// xbc 06/21/97

inherit ITEM;

void create()
{
	set_name("荷叶", ({"he ye", "lotus leaf"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一片大大的绿绿的荷叶。\n");
		set("unit", "片");
		set("value", 0);
	}
}
