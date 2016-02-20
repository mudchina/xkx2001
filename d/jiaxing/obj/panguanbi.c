//Cracked by Roath
// Jay 7/11/96

#include <weapon.h>
inherit CLUB;

void create()
{
    set_name("判官笔", ({"panguan bi", "bi"}));
    set_weight(2000); 
    if( clonep() )
      set_default_object(__FILE__);
    else {
      set("long", "这是一支精钢所铸的判官笔，长一尺六寸，"
		"笔头缚有一簇沾过墨的羊毛。\n");
	set("unit","支");
	set("value",200);
	set("wield_msg","$N把判官笔取在手中，说：你我好朋友，我这秃笔上就不蘸墨了。\n");
	set("unwield_msg","$N把收了起来。\n");
	set("material", "iron");
    }
    init_club(30);

    setup();
}
