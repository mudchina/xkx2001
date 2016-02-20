//Cracked by Roath
// yitian-jian.c

#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit SWORD;
#include "/clone/unique/special_weapon.h"
void create()
{
	set_name("倚天剑", ({ "yitian jian", "yitian", "sword" }) );
	set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "柄");
                set("long", "一柄四尺来长的古剑，剑鞘上用金丝镶着两个字：「倚天」。\n");
		set("value", 10000);
		set("material", "steel");
		set("rigidity", 2000);
                set("wield_msg",
			HIG"只见青光一闪，$N的手中已经多了一柄$n，倚天既出，谁与争锋 !\n"NOR);
                set("unwield_msg", HIG"$N将手中的$n插入腰间的剑鞘。\n"NOR);
                set("unequip_msg", HIG"$N将手中的$n插入腰间的剑鞘。\n"NOR);
        }

	init_sword(150);
        setup();
	::create();
}


