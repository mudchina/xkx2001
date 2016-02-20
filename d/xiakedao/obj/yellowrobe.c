//Cracked by Roath
// yellowrobe.c 
// By long

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(YEL"黄色长袍" NOR, ({"pao", "cloth"}) );
    	set_weight(1500);
    	if( clonep() )
       	set_default_object(__FILE__);
    	else 
	{
	    	set("female_only", 1);
        	set("unit", "件");
		set("long", "这是件质地轻软的黄色长袍。\n");
        	set("material", "cloth");
        	set("armor_prop/armor", 1);
    	}
    setup();
}
