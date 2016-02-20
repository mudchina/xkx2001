//Cracked by Roath
// tiexiao.c 铁箫
// kane

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(YEL "铁箫" NOR,({ "tie xiao", "xiao" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "支");
                set("value", 300);
                set("material", "steel");
                set("long", "一柄普通铁制洞箫，沉甸甸的有些坠手。\n");
                set("wield_msg", "$N从腰间抽出一支铁箫。\n");
                set("unwield_msg", "$N将$n插到领後。\n" );
        }
	init_sword(20);
        setup();

}
