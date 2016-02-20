//Cracked by Roath
#include <weapon.h>
inherit SWORD;

void create()
{
        set_name("清平剑", ({ "cleansword", "sword", "jian" }));
        set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是一柄清澈的精钢剑，很平。\n");
                set("material", "steel");
                set("wield_msg", "$N伸出左手拇指、食指、中指三根手指，握住了剑尖，右手一松，$n突然弹起，剑柄在前，不住幌动，$N说道：“进招吧！”。\n");
                set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
        }
        init_sword(10);
        setup();
}

