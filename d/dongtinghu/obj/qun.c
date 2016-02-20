//Cracked by Roath
// qingbu-qun.c
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(GRN"青布裙"NOR, ({ "qingbu qun", "cloth", "qun" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一件朴素的青布长裙。\n");
		set("unit", "件");
		set("value", 50);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("armor_prop/personality", 3);
		set("female_only", 1);
	}
	setup();
}

