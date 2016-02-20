//Cracked by Roath
// /d/changbai/obj/tiepai.c

#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
        set_name(RED"铁牌"NOR, ({ "tiepai", "dao", "blade" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "面");
                set("value", 1000);
                set("material", "steel");
                set("long", "这是一面铁牌，形状象琵琶。");
                set("wield_msg", "$N抽出一支$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回怀里。\n");
        }
        init_blade(25);
        setup();
}

