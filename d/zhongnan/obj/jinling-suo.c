// jinling-suo金铃索

#include <ansi.h>
#include <weapon.h>
inherit WHIP;
void create()
{
	set_name(HIY "金铃索" NOR, ({ "jinling suo", "suo" }));
       	set("long", "这是一对金铃索，是金丝打做的软兵器。\n");
	set("weight", 300);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("unit", "条");
		set("value", 50000);
                set("material", "gold");
                set("wield_msg", "$N从腰间解下$n拿在手中，索上的金球中发出玎玎声响。\n");
                set("unwield_msg", "$N将手中的$n卷回腰间。\n");
		set("female_only", 1);
	}
        init_whip(40);
	setup();
}	
