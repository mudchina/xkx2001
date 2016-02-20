//Cracked by Roath
// sbgun.c

#include <weapon.h>
inherit CLUB;

void create()
{
        set_name("索拨棍", ({ "suobo gun", "gun" }));
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是一根采参用的索拨棍。用它可以探(tan)到人参的踪迹。\n");
                set("value", 200);
                set("material", "steel");
                set("wield_msg", "$N抽出一根$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回腰间。\n");
              }
        init_club(5);
        setup();
}

