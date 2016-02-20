//Cracked by Roath
// shoutao.c

#include <ansi.h>
#include <armor.h>

inherit FINGER;

void create()
{
	set_name( CYN "铁指套" NOR , ({ "zhitao", "zhi tao" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "这是一个铁铸的指套，套在手指上，可以保护指关节，对练指功的人很有用。\n");
		set("value", 0);
		set("material", "finger");
		set("armor_prop/armor", 5);
	}
	setup();
}
