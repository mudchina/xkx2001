//Cracked by Roath
inherit ITEM;

void create()
{
	set_name("施将军令牌", ({ "shi lingpai", "lingpai", "pai" }));
	set("weight", 400);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","这是一支木令牌，上书一个「施」字。\n");
		set("unit", "支");
		set("material", "wood");
	}
	setup();
}	
