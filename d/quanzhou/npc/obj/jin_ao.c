//Cracked by Roath
// jin_ao.c
// xbc: 11/18/96

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(YEL"窄裉袄"NOR, ({ "ken ao", "ao" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "这是一件金百蝶穿花大红萍缎窄裉，绣工精美，闻起来还有一股淡香。\n");
                set("unit", "件");
                set("value", 400);
                set("material", "cloth");
                set("armor_prop/armor", 5);
                set("armor_prop/personality", 3);
                set("female_only", 1);
	}
	setup();
}

