//Cracked by Roath
// /d/emei/npc/obj/niupi.c
// Shan: 96/07/09

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("Å£Æ¤", ({ "niu pi", "pi", "cow skin" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¿é");
                set("material", "fur");
		set("value", 300);
                set("armor_prop/armor", 2);
        }
        setup();
}

