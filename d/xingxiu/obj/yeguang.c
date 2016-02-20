//Cracked by Roath
// 夜光杯
#include <ansi.h>

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(HIW"夜光杯"NOR, ({"yeguang bei", "bei", "cup"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一祗美玉精雕细琢而成的夜光杯，色彩斑斓，古籍记载夜光杯“白玉之精，光明夜照”。\n");
		set("unit", "祗");
		set("value", 50000);
		set("max_liquid", 4);
		set("worthless", 1);
		set("liquid", ([
			"type": "alcohol",
			"name": "葡萄酒",
			"remaining": 4,
			"drunk_apply": 5,
		]));
	}
}
