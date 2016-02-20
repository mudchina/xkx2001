//Cracked by Roath
// zhubang.c 竹棒

#include <ansi.h>
#include <weapon.h>
inherit STICK;

void create()
{
        set_name(GRN"钓鱼杆"NOR, ({ "fishing pole", "pole" }));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是一根竹子作的钓鱼杆。\n");
                set("value", 250);
                set("material", "steal");
                set("wield_msg", "$N抽出一根$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回腰间。\n");
        }
        init_stick(10);
        setup();
}
