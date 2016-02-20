//Cracked by Roath
// hupi.c 虎皮
// ywz 09/05/1996

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(HIY "虎皮" NOR, ({ "hupi", "pi" }) );
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("value", 5000);
		set("material", "cloth");
		set("long",
		"这是一块从长白虎身上取下的皮，穿上它能够御寒保暖，并能有效的躲避攻击。\n");
		set("wear_msg", HIY "$N穿上$n，呵，暖和极了！\n" NOR);
		set("remove_msg", HIY "$N脱下$n，叠好放在身边。\n" NOR);
		set("unwear_msg", HIY "$N脱下$n，叠好放在身边。\n" NOR);
		set("armor_prop/armor", 50);
	}
	setup();
}
