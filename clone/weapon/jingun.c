//Cracked by Roath
// qimeigun.c
#include "ansi.h"
#include <weapon.h>

inherit CLUB;

void create()
{
	set_name(HIY "黄金棍" NOR, ({ "huangjin gun", "gun" }));
        set_weight(30000);
        if (clonep())
                set_default_object(__FILE__);
        else {
		set("unit", "根");
		set("long", "这是一根黄金所铸的大棍，长达七尺，十分沉重，使开来两丈之内一团黄光，端是厉害之极。\n");
                set("value", 15000000);
                set("material", "gold");
		set("wield_msg", "$N抽出一根$n，在手中一抖。\n");
		set("unequip_msg", "$N将手中的$n背回身后。\n");
        }
        init_club(35);
        setup();
}

