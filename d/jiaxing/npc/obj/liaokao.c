//Cracked by Roath
inherit ITEM;

void create()
{
	set_name("镣铐", ({ "liaokao" }));
	set("weight", 3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long",
		"这是一副精钢制成的镣铐，牢牢地箍在你的手腕和脚踝上。\n");
		set("unit", "副");
		set("no_drop", "你还没打开它呢。\n");
                set("no_get", "这样东西不能离开那儿。\n");
	}

	setup();
}	
