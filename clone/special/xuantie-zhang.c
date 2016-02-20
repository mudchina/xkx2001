//Cracked by Roath
#include <weapon.h>
#include <ansi.h>
inherit SKILL;
inherit STAFF;

int query_autoload() { return 1; }

void create()
{
	set_name(HIW+BLK"玄铁灵蛇杖"NOR, ({ "lingshe zhang", "staff", "shezhang" }));
		set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
	   set("unit", "根");
	   set("long", HIW BLK"一根弯弯曲曲的黑色粗杖，似是钢铁所制，杖头铸着个裂口而笑的人头，人头口中露出尖利雪白的牙齿。\n"+
		HIW"两条银鳞闪闪的小蛇，不住的蜿蜒上下，是西域小鱼儿用最毒的灵蛇与怪蛇杂交培育出来的。\n"NOR);
		set("value", 5000000);
		set("material", "steel");
		set("wield_msg", HIW"杖端的银蛇蜿蜒上下，呲呲做响。\n"NOR);
		set("unwield_msg", HIR"$N将手中的$n"HIR"放了下来。\n"NOR);
		set("poison_applied", 100);
		set("snake_type","灵蛇");
		set("snake", 2);
	}
	init_staff(130);
	setup();
}

void init()
{
	add_action("convert","bian");
}

int wield()
{
	object me = environment();
	object ob = this_object();

	if( !wizardp(me) && me->query("id") != "litfish" )
	{
		message_vision(HIR"$N手中的$n"HIR"突然像活了一样，向$N猛咬一口！\n"NOR, me, ob);
		me->apply_condition("bt_poison", random(100) +
				    me->query_condition("bt_poison"));
		ob->move(environment(me));
		return 0;
	}
	else if (::wield())
	{
		message_vision(HIR"$N抽出一根$n"HIR"握在手中，与蛇杖连成一体，让人不寒而栗！\n"NOR, me, ob);
		me->add("neili", -100);
		return 1;
	}
		return 1;
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{

	if (random(me->query_skill("lingshe-zhang",1))>30 ) {
	      victim->apply_condition("bt_poison",
				    random(me->query_skill("lingshe-zhang", 1)/2) +
	       victim->query_condition("bt_poison"));
	if (victim->query("poisoner") != me)
		victim->set("poisoner", me);
	}
}

int convert(string arg)
{
	object me = this_player();
	object ob;

	if (arg!="shezhang" && arg!="staff" && arg!="zhang") return 0;
		return notify_fail("你不能化玄铁灵蛇杖为蛇。\n");
}

