//Cracked by Roath
// /d/emei/npc/obj/niupi.c
// Shan: 96/07/09

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("ÑòÆ¤", ({ "yang pi", "pi", "lamb skin" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¿é");
                set("material", "fur");
		set("value", 400);
                set("armor_prop/armor", 3);
        }
        setup();
}

