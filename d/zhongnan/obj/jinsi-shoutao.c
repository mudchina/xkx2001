// jinsi-shoutao.c 金丝手套

#include <armor.h>
#include <ansi.h>

inherit WRISTS;

void create()
{
	set_name(HIY "金丝手套" NOR, ({ "jinsi shoutao", "shoutao" }));
       	set("long", "这是一对金丝手套，莹滑温润，光洁无瑕，真是稀世罕有。\n");
	set("weight", 300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "对");
		set("value", 50000);
		set("material", "gold");
		set("armor_prop/armor", 5);
		set("female_only", 1);
	}
	setup();
}	
