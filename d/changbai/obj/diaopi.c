//Cracked by Roath
// diaopi.c 貂皮
// ywz 09/05/1996

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(HIW "貂皮" NOR, ({ "diaopi", "pi" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("value", 2500);
		set("material", "cloth");
		set("long",
		"长白山上的宝物，穿上它能够御寒保暖，并能有效的躲避攻击。\n");
		set("wear_msg", HIY "$N穿上$n，呵，暖和极了！\n" NOR);
		set("remove_msg", HIY "$N脱下$n，叠好放在身边。\n" NOR);
		set("unwear_msg", HIY "$N脱下$n，叠好放在身边。\n" NOR);
		set("armor_prop/armor", 25);
	}
	setup();
}
