//Cracked by Roath
// guazi.c
// xbc: 11/18/96

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(RED"对衿褂子"NOR, ({ "duijin guazi", "guazi", "gua"}) );
	set_weight(850);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一件做工精细的大红刺缎对衿褂子。\n");
		set("unit", "件");
		set("value", 350);
		set("material", "cloth");
		set("armor_prop/armor", 4);
		set("armor_prop/personality", 3);
	}
	setup();
}

