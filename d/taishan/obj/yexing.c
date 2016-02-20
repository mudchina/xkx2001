//Cracked by Roath
// nightsuit.c
// cleansword

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("夜行水靠", ({ "shui kao", "night suit", "suit" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "这是一件黑光油亮的夜行水靠，穿上后能有效的躲避攻击。\n");
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 5);
        }
        setup();
	set("armor_prop/dodge", 3);
}

void init()
{
}

