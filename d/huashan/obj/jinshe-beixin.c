//Cracked by Roath
// cloth.c 金蛇背心
// qfy July 6, 1996.

#include <armor.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit CLOTH;

void create()
{
        set_name("金蛇背心", ({ "jinshe beixin", "jinshe", "beixin" }) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("value", 100000);
                set("material", "cloth");
		set("long",
		"一件轻柔的蛇皮背心。皮背心上金鳞片片，闪闪生光。是金蛇郎\n"
		"君当年留下的异世之宝，水火不侵，刀枪不入。\n");
		set("wear_msg", HIY "$N披上$n，光芒窜动，化作万条金蛇，令周围的人难以直视。\n" NOR);
		set("unequip_msg", HIY "$N脱下$n，金光有如万蛇四窜，消散无踪。\n" NOR);
                set("armor_prop/armor", 270);
        }
        setup();
	::create();
}
