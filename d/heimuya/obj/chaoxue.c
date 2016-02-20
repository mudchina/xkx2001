//Cracked by Roath
// chaoxue.c
// fear: 1999/12/08

#include <armor.h>
#include <ansi.h>

inherit BOOTS;

void create()
{
        set_name("³¯Ñ¥", ({ "chao xue", "boots", "shoes"}) );
        set_color("$HIC$");
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ë«");
                set("long",  "ÕâÊÇÒ»Ë«Çà¶Ð·Ûµ×³¯Ñ¥¡£\n");
                set("value", 1000);
                set("material", "cloth");
                set("armor_type", "boots");
                set("armor_prop/armor", 2);
        }

}
