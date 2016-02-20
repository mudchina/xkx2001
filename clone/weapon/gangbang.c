//Cracked by Roath
// gangbang.c 钢棒
#include <ansi.h>
#include <weapon.h>
inherit STICK;

void create()
{
        set_name("钢棒", ({ "gang bang", "bang" }));
        set_weight(9000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是一根精钢打造的长棒。\n");
                set("value", 400);
                set("material", "steel");
                set("wield_msg", "$N抽出一根$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回腰间。\n");
        }
        init_stick(25);
        setup();
}
