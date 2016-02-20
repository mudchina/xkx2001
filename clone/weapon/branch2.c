//Cracked by Roath
// branch2.c
// Jay 7/4/96

#include <ansi.h>
#include <weapon.h>
inherit CLUB;

void create()
{
    set_name(YEL"大树枝"NOR, ({"shuzhi", "zhi", "branch"}));
    set_weight(500+random(500)); 
    if( clonep() )
      set_default_object(__FILE__);
    else {
      set("long", "这是一根大树枝。\n");
	set("unit","根");
	set("wield_msg","$N拔出一根大树枝握在手中。\n");
	set("material", "wood");
    }
    init_club(random(2));

    setup();
}
