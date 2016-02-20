//Cracked by Roath
//yellowbang.c 黄竹棒
#include <ansi.h>
#include <weapon.h>
inherit STICK;

void create()
{
        set_name("黄竹棒", ({ "huang zhubang", "bang", "zhu bang", "zhubang", "stick", "yellow stick" }));
        set_color("$YEL$");
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这根竹棒虽不如打狗棒坚韧，长短轻重却是一般无异，只是色作淡黄，以示与打狗棒有别。\n");
                set("rigidity", 2000);
                set("value", 1000);
                set("material", "bamboo");
                set("wield_msg", "$N抽出一根$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回腰间。\n");
        }
        init_stick(50);
        setup();
}

