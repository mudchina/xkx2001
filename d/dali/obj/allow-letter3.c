//Cracked by Roath
// allow-letter3.c 大理晋级用公文
inherit ITEM;

void create()
{
	set_name("圣旨", ({"sheng zhi", "zhi", "letter"}));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "封");
		set("long","这是一封由当今圣上签发的圣旨，凭此可向卫士领队挑战并晋级武将。\n");
		set("no_get", "这样东西不能离开那儿。\n");
		set("material", "paper");
	}
}

