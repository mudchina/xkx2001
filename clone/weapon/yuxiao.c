//Cracked by Roath
// yuxiao.c 玉箫
// Ryu

#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit SWORD;

void create()
{
        set_name("玉箫",({ "yu xiao", "xiao" }) );
        set_weight(3000);
	set_color(HIG);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 7000000);
		set("rigidity", 10000);
                set("material", "steel");
                set("long", 
		"一柄翠玉制玉箫，通体晶莹碧绿，近吹口处几点朱斑，殷红如血，显然都是\n"
		"数百年乃至上千年的古物。\n");
                set("wield_msg", 
		    HIG "$N从腰间抽出一支玉箫，吹出优雅的箫声。箫声入耳，众人激荡的心情便即平\n"
			"复。$N随即和道：“苍生笑，不再寂聊，豪情仍在痴痴笑笑。”\n"NOR);
                set("unwield_msg", CYN "$N将$n插到领後。\n" NOR);
                set("unequip_msg", CYN "$N将$n插到领後。\n" NOR);
        }
	init_sword(180);
        setup();
	::create();
}
