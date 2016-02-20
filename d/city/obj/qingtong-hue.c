//Cracked by Roath
//青铜护额
//kane

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name( "青铜护额" , ({ "qingtong hue", "hue" }) );
	set_weight(1200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "顶");
                set("long", "这是一顶青铜打制的护额。\n");
		set("value", 500);
		set("material", "bronze");
		set("armor_prop/armor", 8);
	}
	setup();
}
