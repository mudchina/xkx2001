//Cracked by Roath
// shoutao.c

#include <ansi.h>
#include <armor.h>

inherit FINGER;

void create()
{
	set_name( "铁指套", ({ "zhitao", "zhi tao" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "副");
                set("long", "这是一副五个环环相链的铁指套，前端锋利如刃，既可暗藏掌中伤人，又可保护指关节。\n");
		set("value", 250);
		set("material", "iron");
		set("armor_prop/armor", 5);
		set("shaolin",1);
	}
	setup();
}
