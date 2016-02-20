//Cracked by Roath
#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create()
{
	set_name(HIB"毒尸"NOR, ({ "poison corpse","corpse" }));
	set_weight(28000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "具");
		set("long","这是一具经过药物熬炼的尸体，躯干四肢均已缩小，铜皮铁骨，坚韧无比，且周身布满剧毒。\n");
		set("value", 0);
		set("material", "steel");
		set("wield_msg", "$N取出一具$n持在手中。\n");
		set("unwield_msg", "$N将手中的$n小心翼翼收好。\n");
	}
  	init_staff(25);
	setup();
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        object obj;

	if( random(me->query_skill("poison",1)) <
victim->query_skill("force")/3*2 ) {
		message_vision(HIB
"$N突然双目一睁，瞪了$n一眼！！\n"NOR,this_object(), victim);
		tell_object(victim, HIB
"你只觉双目一痛，脑中一晕，似乎被吸入了一个无底深渊！\n");
		victim->start_busy(random(me->query_skill("poison",1)/20));
	}

        if( random(me->query_skill("poison", 1)) > 100 ) {
                victim->apply_condition("xx_poison",
                query_temp("poison_effect")*2+victim->query_condition("xx_corpse_poison"));
        if(victim->query("poisoner") != me)
        victim->set("poisoner", me);
        }
}
