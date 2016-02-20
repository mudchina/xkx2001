//Cracked by Roath
// tyxiaoao.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("圆领小袄", ({ "xiao ao", "ao", "cloth" }) );
	set("long", "一件台夷男子穿的圆领小袄。\n");
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	setup();
}
