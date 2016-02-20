//Cracked by Roath
// weapon: 法铃

#include <weapon.h>
 
inherit HAMMER;
 
void create()
{
        set_name("法铃", ({ "fa ling","fa","ling" }) );           
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "副");                                
		set("value", 10);
                set("material", "iron");                             
                set("long", "这是一副法铃，摇起来叮叮铛铛乱响。\n");
		set("wield_msg", "$N从腰间抽出一副$n，握在手里。\n");
		set("unequip_msg", "$N将$n收起来，挂回腰间。\n");
        }
        init_hammer(1);
	setup();
}
