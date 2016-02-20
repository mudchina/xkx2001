//Cracked by Roath
#include <ansi.h>
#include <weapon.h>
inherit AXE;

void create()
{
        set_name("小铁斧", ({ "xiao tiefu", "axe" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", 
"这是一柄精钢打造的小斧头，似乎不太适合战斗，木匠和樵夫很喜欢用的工具。\n");
                set("value", 200);
                set("material", "steel");
                set("wield_msg", 
"$N「唰」的一声拔出一柄精光闪闪的小斧头握在手里。\n");
                set("unwield_msg", "$N将手中的$n插回腰间。\n");
        }
        init_axe(10);
        setup();
}

