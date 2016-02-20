//Cracked by Roath
// branch3.c
// Jay 7/4/96
#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create()
{
    set_name(YEL"大树干"NOR, ({"shuzhi", "zhi", "branch"}));
    set_weight(1000+random(2000)); 
    if( clonep() )
      set_default_object(__FILE__);
    else {
      set("long", "这是一根折断的大树干。\n");
	set("unit","根");
	set("wield_msg","$N举起一根大树干托在手中。\n");
	set("material", "wood");
    }
    init_staff(random(2));

    setup();
}
