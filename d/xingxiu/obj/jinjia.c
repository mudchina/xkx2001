//Cracked by Roath
// jinjia.c 黄金盔甲
//
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_UNIQUE;

void create()
{
	set_name(HIY"黄金盔甲"NOR, ({ "golden armor", "armor" }) );
	set_weight(26000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一副黄金盔甲，打造得十分精致，胸甲上刻着一头背生翅膀的骆驼。\n西域古国中，只有国王才能以飞骆驼作徽记。\n");
		set("unit", "件");
		set("material", "gold");
		set("value", 50000);
		set("armor_prop/armor", 150);
	}
	setup();
	::create();
}

