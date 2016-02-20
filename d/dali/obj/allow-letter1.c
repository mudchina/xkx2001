//Cracked by Roath
// allow-letter3.c 大理晋级用公文
inherit ITEM;

void create()
{
	set_name("手谕", ({"shou yu", "yu", "letter"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "封");
		set("long","这是一封由傅思归签发的手谕，凭此可向卫士长挑战并申请升级。\n");
		set("no_get", "这样东西不能离开那儿。\n");
		set("material", "paper");
	}
}

