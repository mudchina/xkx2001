//Cracked by Roath
inherit ITEM;

void create()
{
	set_name("徽墨", ({ "hui mo", "mo" }));
	set("weight", 400);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","这是一端安徽出产的墨，是一件希世之珍，最适合送给读书人。\n");
		set("unit", "端");
		set("value", 3000);
		set("material", "gold");
	}
	setup();
}	
