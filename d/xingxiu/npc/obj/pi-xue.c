//Cracked by Roath
#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
	set_name( CYN "皮靴" NOR , ({ "pi xue", "xue" }) );
	set_weight(1200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "双");
		set("long", "一双哈萨克牧民常穿的马靴。");
		set("value", 300);
		set("material", "boots");
		set("armor_prop/armor", 6);
	}
	setup();
}
