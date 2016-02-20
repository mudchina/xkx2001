//Cracked by Roath

#include <ansi.h>
#include <armor.h>
inherit HANDS;

void create()
{
	set_name( HIY "臂钏" NOR, ({ "bi chuan", "chuan" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "只");
                set("long", "这是一银制的臂钏，上面盘着一条小蛇。\n");
		set("value", 150);
		set("material", "hands");
		set("armor_prop/armor", 4);
	}
	setup();
}
