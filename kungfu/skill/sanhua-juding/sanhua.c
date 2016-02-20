//Cracked by Roath
//  /k  ungfu/skill/sanhua-juding/sanhua.c 三花聚顶
// sdong 07/98
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	int damage,skill,wap,wdp;
	string *limb, type, result, str,msg;

	type = "内伤";

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("三花聚顶只能对战斗中的对手使用。\n");

	if( me->query_temp("sanhua") )
		return notify_fail("你已在使用三花聚顶了！\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("空手才能施展三花聚顶！\n");

	if( me->query_skill_mapped("strike") != "sanhua-juding" )
		return notify_fail("你所用的并非三花聚顶掌，不能施展三花聚顶！\n");

	if( me->query_skill_prepared("strike") != "sanhua-juding" )
                return notify_fail("你所备的并非三花聚顶掌，不能施展三花聚顶！\n");

	if( me->query_skill_mapped("force") != "xiantian-gong" )
                return notify_fail("你所用的并非先天功，施展不出三花聚顶！\n");

	if( me->query_skill("force") < 135 )
		return notify_fail("你的先天功火候未到，无法施展三花聚顶！\n");

	if( me->query_skill("strike") < 135 )
		return notify_fail("三花聚顶需要精湛的三花聚顶掌方能有效施展！\n");

	if( me->query("neili") <= 300 )
		return notify_fail("你的内力不够使用三花聚顶！\n");
	if( me->query("jingli") <= 200 )
		return notify_fail("你的精力不够使用三花聚顶！\n");	
	if( me->query("jing") <= 200 )
		return notify_fail("你的精不够使用三花聚顶！\n");


	msg = HIM"$N运起玄门先天功，内力遍布全身，头顶冒出丝丝热气，竟然呈现三朵莲花，紧跟劈出一掌，一股气劲似浪潮一般向$n袭来！\n\n"NOR;
	message_vision(msg, me, target);

	me->set_temp("sanhua", 1);

	skill =  ( me->query_skill("sanhua-juding")
		+ me->query_skill("force") ) / 2;

	me->add_temp("apply/attack", skill/2);
	me->add_temp("apply/damage",  skill/6);
	me->add_temp("apply/dodge",  skill/2);
	me->add_temp("apply/parry",  skill/2);
	me->add_temp("apply/defense",  skill/2);

		weapon = target->query_temp("weapon");

		  if( objectp(weapon) )
		{
			wap =   me->query("force")/5
			+ (int)me->query("sanhua-juding")/5
			+ (int)me->query_str()
			+ (int)me->query("jiali");

			wdp = (int)weapon->weight() / 500
			+ (int)weapon->query("rigidity")
			+ (int)target->query_str()
			+ (int)target->query("jiali")
			+ (int)target->query_skill("parry")/3;

			wap = wap/2 + random(wap/2);

			if( wap > 3 * wdp ) {
				message_vision(HIY"只见$N身上的$n"+HIY+"已被一掌震断。\n"NOR, target, weapon);
				weapon->unequip();
				weapon->move(environment(target));
				weapon->set("name", "断掉的" + weapon->query("name"));
				weapon->set("value", 0);
				weapon->set("weapon_prop", 0);
				target->reset_action();
				me->add("neili", -150); // to break weapon takes more neili

			} else if( wap > 2 * wdp ) {
				message_vision(HIW"$N只觉得手中" + weapon->name() + "被一掌震得把持不定，脱手飞出！\n" NOR, target);
				weapon->unequip();
				weapon->move(environment(target));
				target->reset_action();
				me->add("neili", -120); // to break weapon takes more neili

			} else if( wap > wdp ) {
				message_vision("$N只觉得手中" + weapon->name() + "一震，险些脱手！\n", target);
				me->add("neili", -100); // to break weapon takes more neili
			}
		}
		else{
			me->add_temp("apply/attack", skill/2);
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
			me->add_temp("apply/attack", -skill/2);
		}

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	me->add("neili", -skill/2);
	me->add("jingli", -100);
	me->add("jing", -100);
	me->start_busy(random(2));

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/2 :), skill/15);

	return 1;
}

private int remove_effect(object me, int amount)
{
	me->add_temp("apply/attack", -amount);
	me->add_temp("apply/damage", -amount/3);
	me->add_temp("apply/parry", -amount);
	me->add_temp("apply/dodge", -amount);
	me->add_temp("apply/defense", -amount);
	me->delete_temp("sanhua");
	message_vision(
	HIY "\n$N吸了一口气，将内力收回丹田！\n\n" NOR, me);

	return 0;
}
