//Cracked by Roath
#include <weapon.h>
inherit STAFF;

void create()
{
        set_name("禅杖", ({ "chan zhang", "zhang" }));
        set_weight(28000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是一根黑黝黝的镔铁禅杖，约四十来斤，是件称手的重兵器。\n");
                set("value", 250);
                set("material", "steel");
                set("wield_msg", "$N抽出一根$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回腰间。\n");
		set("shaolin",1);
        }
        init_staff(25);
        setup();
}

