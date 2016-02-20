//Cracked by Roath
// hougan.c  ºï¸Î

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("ºï¸Î", ({ "hou gan", "gan" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¿Å");
                set("long", "ÕâÊÇÒ»¿Å×ÏºÚÉ«µÄºï¸Î¡£\n");
                set("value", 1000000000);
                set("medicine", 1);
        }
        setup();
}
