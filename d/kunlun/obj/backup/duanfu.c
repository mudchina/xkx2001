//Cracked by Roath
#include <weapon.h>
inherit THROWING;

void create()
{
        set_name("短斧", ({ "duan fu", "fu", "axe" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "袋");
                set("long", "袋子里放着几柄小斧头，明晃晃的锋利极了。\n");
				set("base_unit", "柄");
				set("value", 150);
                set("material", "steel");
                set("wield_msg", "$N从布袋里拔出一把$n。\n");
                set("unwield_msg", "$N把$n放回布袋里。\n");
        }
        init_throwing(25);
        set_amount(5);
        setup();
}
