//Cracked by Roath
// /clone/unique/cy-jian.c
// 重阳剑
// by sdong 08/01/98

#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit SWORD;
#include "/clone/unique/special_weapon.h"
void create()
{
	set_name(HIB"重阳剑"NOR, ({ "chongyang jian", "chongyang", "jian" }) );
	set_weight(4000);
		  if( clonep() )
					 set_default_object(__FILE__);
		  else {
		set("unit", "柄");
					 set("long", "一柄青光闪闪、寒气森森宝剑。剑刃犹如一泓秋水，剑鞘上用金丝镶着两个字：「重阳」。\n");
		set("value", 10000);
		set("material", "steel");
		set("rigidity", 2000);
					 set("wield_msg",
			HIB"只见青光一闪，$N的手中已经多了一柄$n，剑刃犹如一泓秋水，一望而知是断金切玉的利刃 !\n"NOR);
					 set("unwield_msg", HIG"$N将手中的$n插入腰间的剑鞘。\n"NOR);
					 set("unequip_msg", HIG"$N将手中的$n插入腰间的剑鞘。\n"NOR);
		  }

	init_sword(145);
		  setup();
	::create();
}


