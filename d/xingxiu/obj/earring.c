//Cracked by Roath
#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
	set_name("月牙耳坠", ({ "yueya erzhui", "erzhui", "zhui", "earring" }));
	set("weight", 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "对");
		set("value", 5000);
		set("long", "一对精致的耳坠，月牙形圈环中间镶有一颗白如透明的圆宝石。。\n");
		set("material", "jade");
		set("armor_prop/armor", 2);
		set("female_only", 1);
	}
	setup();
}
