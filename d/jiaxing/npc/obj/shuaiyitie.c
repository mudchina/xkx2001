//Cracked by Roath
inherit ITEM;

void create()
{
	set_name("率意帖", ({ "shuaiyi tie", "tie" }));
	set("weight", 1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long",
		"这是唐朝张旭的狂草真迹「率意帖」，帖上草书大开大阖，"
		"便如一位武林高手展开轻功，窜高伏低，虽然行动迅捷，"
		"却不失高雅的风致。\n");
		set("unit", "张");
		set("value",2000);
	}
	setup();
}	
