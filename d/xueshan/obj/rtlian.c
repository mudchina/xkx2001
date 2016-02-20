//Cracked by Roath

#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	set_name( BLU "人头链" NOR, ({ "rentou lian", "lian" }) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "串");
                set("long", "这是一条用一个个骷髅串起来的人头链。\n");
		set("value", 150);
		set("no_sell",1);
		set("material", "neck");
		set("armor_prop/armor", 7);
	}
	setup();
}
