//Cracked by Roath
// zhenwu.c

#include <ansi.h>
#include <weapon.h>

inherit F_UNIQUE;
inherit SWORD;
#include "/clone/unique/special_weapon.h"
void create()
{
        set_name("真武剑", ({ "zhenwu sword", "zhenwu", "sword" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",
			"只见长剑剑鞘铜绿斑斓，以铜丝嵌着两个篆文：“真武”。\n");
                set("value", 7000);
                set("material", "steel");
		set("rigidity", 1500);
                set("wield_msg", 
			"只听见「飕」地一声，顿觉寒气扑面，$N的手中已经多了一把宝剑——$n。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的剑鞘。\n");
        }

        init_sword(120);
        setup();
	::create();
}
