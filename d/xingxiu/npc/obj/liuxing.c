//Cracked by Roath
// weapon: /d/xingxiu/npc/obj/liuxing.c
// Jay: 6/30/96

#include <weapon.h>
 
inherit HAMMER;
 
void create()
{
        set_name("流星锤", ({ "liuxing chui","hammer","chui" }) );           
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "副");                                
                set("material", "wood");                             
                set("long", "这是一副用枯萎的葫芦填充以细沙制成的流星锤。\n");
		set("wield_msg", "$N从地上捧起一些沙子，把沙子灌入$n中，握在手里。\n");
		set("unequip_msg", "$N将$n中的沙子倒在地上，把葫芦收起来。\n");
        }
        init_hammer(15);
}
