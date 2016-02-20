//Cracked by Roath
// bamboo_stick.c

#include <ansi.h>
#include <weapon.h>
//#include "/clone/unique/special_weapon.h"
inherit F_UNIQUE;

inherit STICK;

void create()
{
	set_name(HIG"打狗棒"NOR, ({"dagou bang", "bang", "stick"}));
	set_weight(5000);

	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", HIG"一根碧绿犹如翡翠般的竹棒。\n"NOR);
		set("value", 8000000);
		set("material", "bamboo");
		set("rigidity", 3000);
		set("wield_msg", "$N抽出一根青光闪闪的绿竹杖抓在手中。\n");
		set("unwield_msg", "$N把手中的打狗棒插回腰中。\n");
	}
	init_stick(130);
	setup();
	::create();
}	
