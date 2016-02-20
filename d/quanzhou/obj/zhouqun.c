//Cracked by Roath
// zhouqun.c
// xbc: 11/18/96

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(GRN"洋绉裙"NOR, ({ "yang zhouqun", "qun", "skirt"}) );
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一条做工精细的翡翠撒花洋绉裙。\n");
		set("unit", "条");
		set("value", 250);
		set("material", "cloth");
		set("armor_prop/armor", 2);
		set("armor_prop/personality", 3);
		set("female_only", 1);
	}
	setup();
}

