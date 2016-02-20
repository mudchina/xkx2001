//Cracked by Roath
// tiebang.c 铁棒
#include <ansi.h>
#include <weapon.h>
inherit STICK;

void create()
{
        set_name("铁棒", ({ "tie bang", "bang" }));
        set_weight(9000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是一根沉甸甸的长棒。\n");
                set("value", 350);
                set("material", "iron");
                set("wield_msg", "$N抽出一根$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回腰间。\n");
        }
        init_stick(25);
        setup();
}
