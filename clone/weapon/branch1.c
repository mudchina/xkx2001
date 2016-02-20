//Cracked by Roath
// branch1.c
// Jay 7/4/96

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
    set_name("小树枝", ({"shuzhi", "zhi", "branch"}));
    set_weight(100+random(100)); 
    if( clonep() )
      set_default_object(__FILE__);
    else {
      set("long", "这是一根小树枝。\n");
	set("unit","根");
	set("wield_msg","$N抽出一根小树枝握在手中。\n");
	set("material", "wood");
    }
    init_sword(random(2));

    setup();
}
