//Cracked by Roath
#include <ansi.h>
#include <weapon.h>
inherit STICK;

void create()
{
        set_name(YEL"狼牙棒"NOR, ({ "langya bang", "bang" }));
        set_weight(25000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是一根碗口粗的狼牙棒，棒的一端倒插着一根根铁钉。\n");
                set("value", 500);
                set("material", "steel");
                set("wield_msg", "$N抽出一根$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回腰间。\n");
        }
        init_stick(50);
        setup();
}

