//Cracked by Roath

#include <armor.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit CLOTH;

void create()
{
	set_name("乌蚕衣", ({ "wucan yi", "yi" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一件由大雪山上的乌蚕蚕丝织成的黑衣，坚韧无比，刀剪不可裁，是以只是由前後两块衣料扣在一起。\n");
		set("material", "cloth");
		set("unit", "件");
		set("value", 50000);
		set("armor_prop/armor", 200);
	}
	setup();
	::create();
}
