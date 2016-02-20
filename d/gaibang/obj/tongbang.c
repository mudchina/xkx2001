//Cracked by Roath
//tongbang.c 铜棒
#include <ansi.h>
#include <weapon.h>
inherit STICK;

void create()
{
        set_name("铜棒", ({ "tong bang", "bang", "tongbang", "stick" "bonze stick" }));
        set_color("$YEL$");
        set_weight(30000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是一根粗短的铜棒，看起来黄澄澄的，重量却不轻。\n");
                set("rigidity", 1000);
                set("value", 5000);
                set("material", "bonze");
                set("wield_msg", "$N抽出一根$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回腰间。\n");
        }
        init_stick(65+ random(10));
        setup();
}

