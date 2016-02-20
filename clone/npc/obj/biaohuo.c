//Cracked by Roath
// clone/npc/obj/biaohuo.c
// sdong, 12/12/98
#include <ansi.h>

inherit ITEM;

void create()
{
		  set_name("镖货", ({ "biao huo", "huo" }));
		  set_weight(10000);
		  set("no_steal", "这东西不能偷。\n");
		  set("long", "这是一大包用油布厚厚包装的东西，不知里面装了些什么。\n");
		  set("material", "steel");
		  set("regidity", 100000000);
		  set("unit", "包");
		  set("value", 10000000);
		  setup();
}

