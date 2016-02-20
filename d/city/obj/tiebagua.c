//Cracked by Roath
#include <ansi.h>
#include <weapon.h>
//inherit THROWING;
inherit COMBINED_ITEM;

void create()
{
        set_name("铁八卦", ({ "tie bagua", "bagua" }) );
        set_weight(10000);
	set_color(BLK);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        	set("long", "铁八卦是纯铁所铸，分量极重，上有八卦图案。\n");
        	set("unit", "枚");
		set("base_unit", "枚");
		set("wield_msg", BLK "$N由口袋里拿出$n。\n" NOR );
		set("unwield_msg", BLK "$N将$n放回口袋中。\n" NOR );
        	set("value", 1600);
//		set("armor_prop/armor", 1);
        }
	set_amount(1);
        setup();
}
