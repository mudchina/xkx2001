//Cracked by Roath
inherit ITEM;

void create()
{
	set_name("玄铁令", ({ "xuantie ling", "ling" }));
	set("weight", 4000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","一块黑兮兮的铁片，一面写着“玄铁之令，有求必应”，另一面写着“摩天崖谢烟客”。\n");
		set("unit", "块");
		set("no_steal", 1);
		set("material", "gold");
	}
	setup();
}	
