//Cracked by Roath
// qimeigun.c

#include <weapon.h>

inherit CLUB;

void create()
{
	set_name("齐眉棍", ({ "qimei gun", "gun" }));
        set_weight(8000);
        if (clonep())
                set_default_object(__FILE__);
        else {
		set("unit", "根");
		set("long", "这是一根桦木白腊棍，举可齐眉，轻重合宜，可攻击大片敌人。\n");
                set("value", 150);
                set("material", "wood");
		set("wield_msg", "$N抽出一根$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插回腰间。\n");
		set("shaolin",1);
        }
        init_club(15);
        setup();
}

