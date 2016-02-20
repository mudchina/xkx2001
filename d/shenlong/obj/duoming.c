//Cracked by Roath
// duoming.c  夺命剑
// ALN Sep / 97

#include <ansi.h>
#include <weapon.h>
inherit SWORD;
#include "/clone/weapon/edge_weapon.h"
void create()
{
        set_name("夺命剑", ({ "duoming jian", "jian" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是一柄轻巧的精钢剑，锋利无比，女剑客们都喜欢配带此剑。\n");
                set("value", 1000);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
        }
        init_sword(30);
        setup();
}
