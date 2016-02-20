//Cracked by Roath
// Jay 7/11/96

#include <weapon.h>
inherit CLUB;

void create()
{
    set_name("旱烟管", ({"han yanguan", "yanguan", "club"}));
    set_weight(500); 
    if( clonep() )
      set_default_object(__FILE__);
    else {
      set("long", "这是一支铜制的旱烟管，里面还剩点烟末。\n");
	set("unit","支");
	set("value",100);
	set("wield_msg","$N摸出一支旱烟管，点上火，叼在嘴角，慢慢喷出烟雾。\n");
	set("unwield_msg","$N把旱烟管在鞋底上嗑一嗑，小心地放回怀里。\n");
	set("material", "iron");
    }
    init_club(10);

    setup();
}
