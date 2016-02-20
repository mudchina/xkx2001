//Cracked by Roath
// tengjia.c 藤甲
//
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(YEL"藤甲"NOR, ({ "tengjia", "armor" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "这是一件用大理某处山区特产的藤条编织成的藤甲，又轻又结实，是护身佳品。\n");
		set("material", "wood");
		set("value", 10);
		set("armor_prop/armor", 75);
	}
	setup();
}

int is_special() { return 1;}

mixed hit_by(object me, object victim, int damage, object weapon)
{
	if (weapon)	return damage*2/3;
	return damage*3/4;
}
