//Cracked by Roath
// Jay 7/11/96

#include <weapon.h>
inherit HAMMER;

void create()
{
    set_name("墓碑", ({"mubei", "bei", "hammer"}));
    set_weight(40000); 
    if( clonep() )
      set_default_object(__FILE__);
    else {
      set("long", "碑上写的是「先考黄府君诚本之墓」。\n");
	set("unit","座");
	set("wield_msg","$N对着地上一座坟磕了个头，说声对不起，搬起一座墓碑。\n");
	set("unwield_msg","$N把墓碑往地上一放，不小心砸到自己的脚。\n");
	set("material", "stone");
    }
    init_hammer(20);

    setup();
}
