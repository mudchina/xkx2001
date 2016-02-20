//Cracked by Roath
// necklace.c 金项链
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIY"金元宝"NOR, ({ "jin yuanbao", "jin", "yuanbao" }));
	set("weight", 9000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("value", 400000);
		set("material", "gold");
	}
	setup();
}	
