//Cracked by Roath
//magua.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name( "马褂" , ({ "ma gua", "gown", "magua", "gua" }));
        set_color("$HIR$");
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一件马褂。是新郎结婚时穿的衣服。\n");
		set("material", "cloth");
		set("unit", "件");
		set("value", 15000);
		set("wear_msg", HIR "$N穿上一件黑色的团龙马褂，披上一条大红绸带。准备拜堂娶亲。\n" NOR);
		set("armor_prop/armor", 10);
		set("unequip_msg", HIM "$N将婚礼马褂脱了下来，显出一身青衣短褂。\n" NOR);
	}
	setup();
}

