//Cracked by Roath
// allow-letter2.c 大理晋级用公文
inherit ITEM;

void create()
{
	set_name("公文", ({"gong wen", "wen", "letter"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "封");
		set("long","这是一封由高候爷签发的公文，凭此可向定安府申请升级。\n");
		set("no_get", "这样东西不能离开那儿。\n");
		set("material", "paper");
	}
}

